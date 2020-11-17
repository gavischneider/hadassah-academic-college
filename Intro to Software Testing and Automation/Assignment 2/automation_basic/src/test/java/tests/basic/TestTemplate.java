package tests.basic;


import org.testng.annotations.Test;

import tests.supers.TestBase;

import org.junit.Before;
import org.junit.After;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.JavascriptExecutor;
import java.util.*;

public class TestTemplate extends TestBase {
	private WebDriver driver;
	  @SuppressWarnings("unused")
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
		    
		    Thread.sleep(3000);
		    String itemPrice = app.driver.findElement(By.cssSelector("#price-value-1")).getText();
		    Thread.sleep(3000);
		    String cartQuantity = app.driver.findElement(By.cssSelector("#topcartlink > a > span.cart-qty")).getText();
		    
		    if (!cartQuantity.equals("(1)")) {
		    	throw new Exception("Cart quantity is not equal to 1!");
		    }
		    
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".cart-label")).click();
		    Thread.sleep(3000);
		    String cartTotal = app.driver.findElement(By.cssSelector("#shopping-cart-form > div.cart-footer > div.totals > div.total-info > table > tbody > tr.order-total > td.cart-total-right > span > strong")).getText();
		    
		    if (!itemPrice.equals(cartTotal)) {
		    	throw new Exception("Item Price and Cart total do not match!");
		    };
		    
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
		    String finalTotal = app.driver.findElement(By.cssSelector("#shopping-cart-form > div.table-wrapper > table > tbody > tr > td.unit-price > span")).getText();
		    if (!finalTotal.equals(cartTotal)) {
		    	throw new Exception("Final Total and Cart Total do not match!");
		    }
		    app.driver.findElement(By.cssSelector(".confirm-order-next-step-button")).click();
		    Thread.sleep(3000);
		    {
		    	WebElement element = app.driver.findElement(By.cssSelector("body > div.master-wrapper-page > div.master-wrapper-content > div > div > div > div.page-body.checkout-data > div > div.buttons > input"));
		      Actions builder = new Actions(app.driver);
		      builder.moveToElement(element).perform();
		    }
		    Thread.sleep(3000);
		    String message = app.driver.findElement(By.cssSelector("body > div.master-wrapper-page > div.master-wrapper-content > div > div > div > div.page-title > h1")).getText();
		    
		    if (!message.equals("Thank you")) {
		    	throw new Exception("Message does not say thank you!");
		    }
		    
		    Thread.sleep(3000);
		    app.driver.findElement(By.cssSelector(".order-completed-continue-button")).click();
		    String newMessage = app.driver.findElement(By.cssSelector("body > div.master-wrapper-page > div.master-wrapper-content > div > div > div > div > div.topic-block > div.topic-block-title > h2")).getText();
		    
		    if (!newMessage.equals("Welcome to our store")) {
		    	throw new Exception("New message does not say welcome to our store!");
		    }
		    
		    String newCartQuantity = app.driver.findElement(By.cssSelector("#topcartlink > a > span.cart-qty")).getText();
		    
		    if (!newCartQuantity.equals("(0)")) {
		    	throw new Exception("New cart quantity does not equal 0!");
		    }
		    app.driver.close();
		  


			endTestSuccess();
		} catch (Throwable t) {
			onTestFailure(t);
		}
	}
	

}
