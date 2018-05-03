package com.tom.apitest;


import static org.hamcrest.Matchers.*;
import static org.junit.Assert.*;
import org.junit.*;

import io.restassured.RestAssured;


public class GetAccountTest {

	
	@Test
	public void getAccount() {
		
				
		RestAssured.get("http://127.0.0.1:8080/accountapp/api/accounts/json").
			then().statusCode(200).log().all();
		
		RestAssured.get("http://127.0.0.1:8080/accountapp/api/accounts/json/1/?format=json").
			then().
			assertThat().	
			body("firstName", equalTo("Tim")); 
		
		
	}

}
