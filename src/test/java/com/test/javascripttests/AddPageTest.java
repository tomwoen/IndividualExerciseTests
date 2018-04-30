package com.test.javascripttests;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.firefox.FirefoxProfile;

public class AddPageTest {

	private static WebDriver driver;
	
	@Before
	public void setUp() {
		
		System.setProperty("webdriver.gecko.driver", "C:\\Users\\Thoma\\IdeaProjects\\geckodriver-v0.20.0-win64\\geckodriver.exe");
		
		driver = new FirefoxDriver();
		
	}
	
	@Test
	public void testAddAccountThroughUI() throws InterruptedException {
		
		driver.get("http://127.0.0.1:8080/accountapp/addaccountpage.html");
		
		Thread.sleep(10000);
		
		WebElement firstName = driver.findElement(By.id("fname"));
		firstName.sendKeys("Tom");
		
		WebElement lastName = driver.findElement(By.id("lname"));
		lastName.sendKeys("Owen");
		
		WebElement accNumber = driver.findElement(By.id("accno"));
		accNumber.sendKeys("1234");
		
		WebElement submit = driver.findElement(By.id("add-account"));
		submit.click();
		
		Thread.sleep(2000);
		
		String actual = driver.switchTo().alert().getText();	
		
		String expected = "Account Successfully Added";
		
		assertEquals(expected, actual);
	}
	
	@After
	public void tearDown () {
		
		driver.quit();
	}

}
