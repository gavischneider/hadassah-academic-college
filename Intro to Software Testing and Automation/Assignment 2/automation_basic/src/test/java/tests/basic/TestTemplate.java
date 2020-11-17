package tests.basic;


import org.testng.annotations.Test;

import tests.supers.TestBase;

import org.junit.Before;
import org.junit.After;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.JavascriptExecutor;
import java.util.*;

public class TestTemplate extends TestBase {
	private WebDriver driver;
	  private Map<String, Object> vars;
	  JavascriptExecutor js;
	  @Before
	  public void setUp() {
	    driver = new ChromeDriver();
	    js = (JavascriptExecutor) driver;
	    vars = new HashMap<String, Object>();
	  }
	  @After
	  public void tearDown() {
	    driver.quit();
	  }


	@Test
	public void test() {
		try {

			//app.getDriver().get("http://selenium2.ru/");
			app.driver.get("https://demo.nopcommerce.com/");
		    app.driver.manage().window().setSize(new Dimension(1920, 1080));
		    app.driver.findElement(By.linkText("Log in")).click();
		    app.driver.findElement(By.id("Email")).click();
		    app.driver.findElement(By.id("Email")).sendKeys("abc@abc.com");
		    app.driver.findElement(By.id("Password")).click();
		    app.driver.findElement(By.id("Password")).sendKeys("123456");
		    app.driver.findElement(By.cssSelector(".login-button")).click();
		    app.driver.findElement(By.linkText("Computers")).click();
		    app.driver.findElement(By.cssSelector(".item-box:nth-child(1) img")).click();
		    app.driver.findElement(By.cssSelector(".item-box:nth-child(1) img")).click();
		    app.driver.findElement(By.cssSelector("#product_attribute_input_3 li:nth-child(1) > label")).click();
		    app.driver.findElement(By.id("add-to-cart-button-1")).click();
		    app.driver.findElement(By.cssSelector(".cart-label")).click();
		    app.driver.findElement(By.id("termsofservice")).click();
		    app.driver.findElement(By.id("checkout")).click();
		    app.driver.findElement(By.cssSelector(".new-address-next-step-button:nth-child(1)")).click();
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".shipping-method-next-step-button")).click();
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".payment-method-next-step-button")).click();
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".payment-info-next-step-button")).click();
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".confirm-order-next-step-button")).click();
		    Thread.sleep(3000);
		    {
		      WebElement element = app.driver.findElement(By.cssSelector(".order-completed-continue-button"));
		      Actions builder = new Actions(driver);
		      builder.moveToElement(element).perform();
		    }
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".order-completed-continue-button")).click();
		    app.driver.close();
		  


			endTestSuccess();
		} catch (Throwable t) {
			onTestFailure(t);
		}
	}


}
