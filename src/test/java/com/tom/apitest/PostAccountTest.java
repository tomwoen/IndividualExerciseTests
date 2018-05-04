package com.tom.apitest;

import static org.junit.Assert.*;

import org.junit.Test;

import com.google.gson.JsonObject;

import io.restassured.RestAssured;
import io.restassured.response.Response;
import io.restassured.specification.RequestSpecification;

public class PostAccountTest {

	@Test
	public void postAccount() {
		
		RestAssured.baseURI = "http://127.0.0.1:8080/accountapp/api/accounts/";
		RequestSpecification request = RestAssured.given();
		
		JsonObject requestParams = new JsonObject();
		requestParams.addProperty("firstName","Phil");
		requestParams.addProperty("lastName","Mitchell");
		requestParams.addProperty("accountNumber","1235");
		
		request.body(requestParams.toString());
		Response response = request.post("/json");
		
		int statusCode = response.getStatusCode();
		assertEquals(statusCode, 200);
		
	}

}
