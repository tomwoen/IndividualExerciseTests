package com.test.javascripttests;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.*;
import org.openqa.selenium.firefox.FirefoxDriver;

public class DeletePageTest {

	private static WebDriver driver;
	
	@Before
	public void setUp() {
		
		System.setProperty("webdriver.gecko.driver", "C:\\Users\\Thoma\\IdeaProjects\\geckodriver-v0.20.0-win64\\geckodriver.exe");
		driver = new FirefoxDriver();
	}
	
	@Test
	public void testDeleteThroughUI() throws InterruptedException {
		
		driver.get("http://127.0.0.1:8080/accountapp/updateaccountpage.html");
		
		Thread.sleep(10000);
		
		WebElement id =driver.findElement(By.id("accid"));
		id.sendKeys("1");
		
		WebElement firstName = driver.findElement(By.id("fname"));
		firstName.sendKeys("Tom");
		
		WebElement lastName = driver.findElement(By.id("lname"));
		lastName.sendKeys("Owen");
		
		WebElement accNumber = driver.findElement(By.id("accno"));
		accNumber.sendKeys("1234");
		
		Thread.sleep(2000);
		
		WebElement delete = driver.findElement(By.id("delete-account"));
		
		delete.click();
		
		Thread.sleep(2000);
		
		String actual = driver.switchTo().alert().getText();	
		
		String expected = "Account Successfully Deleted";
		
		assertEquals(expected, actual);
		
	}
	
	@After
	public void tearDown() {
		
		driver.quit();
	}

}
