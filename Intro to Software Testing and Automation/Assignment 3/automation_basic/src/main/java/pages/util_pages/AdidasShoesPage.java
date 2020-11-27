package util;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.testng.Assert;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class AdidasShoesPage extends MenusPage{

	public AdidasShoesPage(MainPageManager pages) {
		super(pages);
		// TODO Auto-generated constructor stub
	}

	public AdidasShoesPage ensurePageLoaded() {
		 super.ensurePageLoaded();
		   
		 waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.id("add-to-cart-button-25"))));
		   
		 return this;
	}
	
	public AdidasShoesPage addToCart() {
		driver.findElement(By.id("add-to-cart-button-25")).click();

		GenUtils.sleepMillis(6000);// wait green message to disappear
		
		return this;
		
	}
	
	public AdidasShoesPage checkCart() {
		log.info("Check correct amount of items in cart");
		String expectedCartAmount = "(1)";
		String cartAmount = driver.findElement(By.xpath("//span[@class='cart-qty']")).getText();
		Assert.assertTrue(cartAmount.equals(expectedCartAmount),
				"Expected cart amount to be " + expectedCartAmount + " but received " + cartAmount + " instead.");
		return this;
	}
	
	public CartPage goToCartPage() {
		log.info("Go to cart and confirm price");
		driver.findElement(By.cssSelector(".cart-label")).click();
		GenUtils.sleepMillis(3000);
		return pages.cartPage.ensurePageLoaded();
	}
	

}
