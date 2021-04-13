---
title: "Spring JDBC"
excerpt: 개념 정리
permalink: /study/27
categories:
  - study
  - spring
tags:
  - study
  - spring
  
last_modified_at: 2021-04-13
---  
### Spring JDBC 학습 테스트  
1. Querying  
- queryForObject(쿼리문, 기댓값타입)  
```java
public int count() {
    String sql = "select count(*) from customers";
    return jdbcTemplate.queryForObject(sql, Integer.class);
}
```  
- queryForObject(쿼리문, 기댓값타입, ?표 자리 값)   
```java
public String getLastName(Long id) {
    String sql = "select last_name from customers where id = ?";
    return jdbcTemplate.queryForObject(sql, String.class, id);
}
```  
- query(쿼리문, rowMapper)  
```java
public List<Customer> findAllCustomers() {
    String sql = "select id, first_name, last_name from customers";
    return jdbcTemplate.query(sql, (resultSet, rowNum) -> {
        return new Customer(
            resultSet.getLong("id"),
            resultSet.getString("first_name"),
            resultSet.getString("last_name")
        );
    });
}
```  
- queryForObject(쿼리문, rowMapper, ?표 자리 값) / query(쿼리문, 기댓값타입, ?표 자리 값)  
rowMapper는 쿼리문에 여러 값을 전달해야할 때 사용할 수 있는 것이다.  
```java
public Customer findCustomerById(Long id) {
    String sql = "select id, first_name, last_name from customers where id = ?";
    RowMapper<Customer> rowMapper = (resultSet, rowNum) -> {
        Customer customer = new Customer(
            resultSet.getLong("id"),
            resultSet.getString("first_name"),
            resultSet.getString("last_name")
        );
        return customer;
    };
    return jdbcTemplate.queryForObject(sql, rowMapper, id);
}
public List<Customer> findCustomerByFirstName(String firstName) {
    String sql = "select id, first_name, last_name from customers where first_name = ?";
    return jdbcTemplate.query(sql, (resultSet, rowNum) -> {
        return new Customer(
            resultSet.getLong("id"),
            resultSet.getString("first_name"),
            resultSet.getString("last_name")
        );
    }, firstName);
}
```  
<br>

2. Updating  
- insert: update(쿼리문, ?표 개수만큼 추가)  
```java
public void insert(Customer customer) {
    String sql = "insert into customers (first_name, last_name) values (?, ?)";
    jdbcTemplate.update(sql, customer.getFirstName(), customer.getLastName());
}
```  
- delete: update(쿼리문, ?표 개수만큼 추가): 삭제한 것 id 반환  
```java
public int delete(Long id) {
    String sql = "delete from customers where id = ?";
    return jdbcTemplate.update(sql, id);
}
```  
- update(PreparedStatementCreator psc, Keyholder keyholder): 쿼리 결과로 변경된 행의 개수 리턴  
자동 생성된 키 값을 알아낼 수 없기 때문에 keyholder를 사용한다.  
이 keyHolder의 두번째 인자에는 자동 생성되는 컬럼의 이름을 넣는다.  
```java
public long insertWithKeyHolder(Customer customer) {
    final String sql = "insert into customers (first_name, last_name) values (?, ?)";
    KeyHolder keyHolder = new GeneratedKeyHolder();
    jdbcTemplate.update(connection -> {
        PreparedStatement ps = connection.prepareStatement(sql, new String[] {"id"}); //여기에 자동생성되는 컬럼의 이름을 넣는다.  
        ps.setString(1, customer.getFirstName());
        ps.setString(2, customer.getLastName());
        return ps;
    }, keyHolder);
    return keyHolder.getKey().longValue();
}
```  

3. NamedParameterJdbcTemplate  
NamedParameterJdbcTemplate: ?가 있는ㄴ 쿼리문을 실행시켜주는 jdbcTemplate  
MapSqlParameterSource: SqlParameterSource 중 하나로 이름과 요소를 매핑해주는 것  
BeanPropertySqlParameterSource: javaBean 객체 자체를 넘겨 매핑해주는 것  
public <T> T queryForObject(String sql, SqlParameterSource paramSource, Class<T> requiredType): (쿼리문, 전달할source, 기댓값타입)  
```java
public int useMapSqlParameterSource(String firstName) {
    String sql = "select count(*) from customers where first_name = :first_name";
    SqlParameterSource mapSqlParameterSource = new MapSqlParameterSource("first_name", firstName);
    return this.namedParameterJdbcTemplate.queryForObject(sql, mapSqlParameterSource, Integer.class);
}
```  
```java
public int useBeanPropertySqlParameterSource(Customer customer) {
    String sql = "select count(*) from customers where first_name = :firstName";
    SqlParameterSource sqlParameterSource = new BeanPropertySqlParameterSource(customer);
    return this.namedParameterJdbcTemplate.queryForObject(sql, sqlParameterSource, Integer.class);
}
```  