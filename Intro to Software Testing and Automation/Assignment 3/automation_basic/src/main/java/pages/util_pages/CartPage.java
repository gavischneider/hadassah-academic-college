package util;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.testng.Assert;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class CartPage extends MenusPage {

	public CartPage(MainPageManager pages) {
		super(pages);
		// TODO Auto-generated constructor stub
	}
	
	public CartPage ensurePageLoaded() {
		 super.ensurePageLoaded();
		   
		 waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.cssSelector(".cart-label"))));
		   
		 return this;
	}
	
	public CartPage confirmPriceInCart() {
		String cartPrice = driver.findElement(By.xpath("//span[@class='value-summary']/strong")).getText();
		Assert.assertTrue(cartPrice.equals(cartPrice),
				"Expected price is " + cartPrice + " but the price in the cart is " + cartPrice);
		return this;
	}
	
	
	public CheckoutPage goToCheckoutPage() {
		GenUtils.sleepMillis(3000);
		log.info("Click on box verification if not already clicked");
		if (!driver.findElement(By.id("termsofservice")).isSelected())
			driver.findElement(By.id("termsofservice")).click();
		
		GenUtils.sleepMillis(3000);
		log.info("Click on 'checkout' button");
		driver.findElement(By.id("checkout")).click();

		GenUtils.sleepMillis(3000);
		return pages.checkoutPage.ensurePageLoaded();
	
	}

	

}
