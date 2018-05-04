package com.tom.apitest;


import static org.hamcrest.Matchers.*;

import org.easetech.easytest.annotation.Repeat;
import org.junit.*;

import io.restassured.RestAssured;


public class GetAccountTest {
		
	@Test
	@Repeat(times=1000)
	public void getAccount() {
			
		RestAssured.get("http://127.0.0.1:8080/accountapp/api/accounts/json").
			then().statusCode(200).log().all();
		
		
		
		RestAssured.get("http://127.0.0.1:8080/accountapp/api/accounts/json/6/?format=json").
			then().
			assertThat().	
			body("firstName", equalTo("Tim")); 
		}

}
