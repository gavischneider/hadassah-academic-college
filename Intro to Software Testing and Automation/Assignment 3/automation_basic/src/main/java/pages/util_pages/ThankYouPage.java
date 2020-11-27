package util;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.testng.Assert;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;
import pages.util_pages.HomePage;

public class ThankYouPage extends MenusPage {

	public ThankYouPage(MainPageManager pages) {
		super(pages);
		// TODO Auto-generated constructor stub
	}
	
	public ThankYouPage ensurePageLoaded() {
		 super.ensurePageLoaded();
		   
		 waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.xpath("//div[@class='page-title']/h1"))));
		   
		 return this;
	}

	public ThankYouPage verify() {
		String confirmText1 = "Thank you";
		String confirmText2 = "Your order has been successfully processed!";
		String receivedText1 = driver.findElement(By.xpath("//div[@class='page-title']/h1")).getText();
		String receivedText2 = driver.findElement(By.xpath("//div[@class='title']/strong")).getText();
		Assert.assertTrue(confirmText1.equals(receivedText1),
				"Expected text is " + confirmText1 + " but instead received " + receivedText1);
		Assert.assertTrue(confirmText2.equals(receivedText2),
				"Expected text is " + confirmText2 + " but instead received " + receivedText2);
		driver.findElement(By.cssSelector(".order-completed-continue-button")).click();
		return this;
	}
	
	public HomePage goToHomePage() {
		log.info("Check that we've returned to the main page and that the cart is empty");
		GenUtils.sleepMillis(2000);
		return pages.homePage;
	}

}
