package util;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.Select;
import org.testng.Assert;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class CheckoutPage extends MenusPage {

	public CheckoutPage(MainPageManager pages) {
		super(pages);
		// TODO Auto-generated constructor stub
	}
	
	public CheckoutPage ensurePageLoaded() {
		 super.ensurePageLoaded();
		   
		 waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.id("BillingNewAddress_CountryId"))));
		   
		 return this;
	}
	
	public CheckoutPage enterAddress() {
		log.info("---------------------- MADE IT TO CHECKOUT PAGE--------------------------");
		log.info("Enter address");

		Select country = new Select(driver.findElement(By.id("BillingNewAddress_CountryId")));
		country.selectByVisibleText("United States");
		GenUtils.sleepMillis(2000);
		Select state = new Select(driver.findElement(By.id("BillingNewAddress_StateProvinceId")));
		state.selectByVisibleText("Alabama");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.id("BillingNewAddress_City")).sendKeys("A");
		driver.findElement(By.id("BillingNewAddress_Address1")).sendKeys("V");
		driver.findElement(By.id("BillingNewAddress_ZipPostalCode")).sendKeys("123456");
		driver.findElement(By.id("BillingNewAddress_PhoneNumber")).sendKeys("1234567");
		driver.findElement(By.cssSelector(".new-address-next-step-button:nth-child(1)")).click();
		
		return this;
	}
	
	public CheckoutPage acceptShippingAndPaymentMethods() {
		log.info("Accept current shipping method");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.cssSelector(".shipping-method-next-step-button")).click();

		log.info("Accept current payment method");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.cssSelector(".payment-method-next-step-button")).click();

		log.info("Accept address confirmation");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.cssSelector(".payment-info-next-step-button")).click();
		
		return this;
	}
	
	public CheckoutPage checkAndConfirmOrder(String price) {
		log.info("Check order total and confirm order");
		GenUtils.sleepMillis(2000);
		String checkoutPrice = driver.findElement(By.xpath("//span[@class='product-subtotal']")).getText();
		Assert.assertTrue(price.equals(checkoutPrice),
				"Expected price is " + price + " but the price on the checkout page is " + checkoutPrice);
		
		return this;
	}
	
	public ThankYouPage goToThankYouPage() {
		driver.findElement(By.cssSelector(".confirm-order-next-step-button")).click();
		log.info("Check that proper confirmation text has been received and click continue");
		GenUtils.sleepMillis(2000);
		return pages.thankYouPage.ensurePageLoaded();
	}

	

}
