package com.test.javascripttests;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;

public class UpdatePageTest {
 
	private static WebDriver driver;

	@Before
	public void setUp() {
		
		System.setProperty("webdriver.gecko.driver", "C:\\Users\\Thoma\\IdeaProjects\\geckodriver-v0.20.0-win64\\geckodriver.exe");
		driver = new FirefoxDriver();
	}
		
	
	@Test
	public void testUpdatePageUI() throws InterruptedException {
		
		driver.get("http://127.0.0.1:8080/accountapp/updateaccountpage.html");
			
		Thread.sleep(10000);
		
		WebElement id =driver.findElement(By.id("accid"));
		id.sendKeys("1");
		
		WebElement firstName = driver.findElement(By.id("fname"));
		firstName.sendKeys("Bill");
		
		WebElement lastName = driver.findElement(By.id("lname"));
		lastName.sendKeys("Owen");
		
		WebElement accNumber = driver.findElement(By.id("accno"));
		accNumber.sendKeys("1234");
		
		WebElement update = driver.findElement(By.id("update-account"));
		
		update.click();
		
		Thread.sleep(2000);
		
		String actual = driver.switchTo().alert().getText();	
		
		String expected = "Account Successfully Updated";
		
		assertEquals(expected, actual);
	}
	
	
	@After
	public void tearDown() {
		
		driver.quit();
	}

}
