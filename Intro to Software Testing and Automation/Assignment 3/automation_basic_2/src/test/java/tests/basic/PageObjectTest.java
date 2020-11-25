package tests.basic;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.ui.Select;
import org.testng.Assert;
import org.testng.annotations.Test;

import tests.supers.TestBase;
import util.GenUtils;

public class PageObjectTest extends TestBase {

	String timestamp, email, password, price;

	@Test
	public void test() {
		try {

			initParameter();
			app.getDriver().get("https://demo.nopcommerce.com/");

			registerNewUser();
			shoppingProcessEndToEnd();

			endTestSuccess();
		} catch (Throwable t) {
			onTestFailure(t);
		}
	}

	private void initParameter() {
		timestamp = GenUtils.getCurrentTimestamp(GenUtils.TIME_FORMAT_ddMMyyHHmmSSS);
		email = "randomEmail" + timestamp + "@gmail.com";
		password = "123456";
		price = "";
	}

	private void registerNewUser() {

		app.pages().menusPage.clickRegister().ensurePageLoaded().chooseGender("male")
				.setFirstName("Name1").setLastName("Name2")
				.selectBirthdayDay("1").selectBirthdayMonth("January").selectBirthdayYear("1910")
				.setMail(email)
				.setPassword(password).setPasswordVerification(password)
				.clickRegisterButton()
				.verifySuccessMessage().clickContinue().verifyHomeText().logout();
	}

	private void shoppingProcessEndToEnd() {

		WebDriver driver = app.getDriver();

		app.pages().menusPage.clickLogin().ensurePageLoaded().setEmail(email).setPassword(password).clickLoginButton();


		log.info("Go to the 'Apparel' category");
		driver.findElement(By.linkText("Apparel")).click();
		log.info("Go to the 'Shoes' category");
		driver.findElement(By.linkText("Shoes")).click();
		GenUtils.sleepMillis(2000);

		// remember the price
		price = driver.findElement(By.xpath(
				"//div[@class='description' and contains(text(),'adidas')]/..//span[contains(@class,'actual-price')]"))
				.getText();
		log.debug("The price is " + price);

		log.info("Click on picture");
		driver.findElement(
				By.xpath("//div[@class='picture']//img[contains(@title,'adidas')]"))
				.click();
		GenUtils.sleepMillis(3000);// wait item description page is loaded
		driver.findElement(By.id("add-to-cart-button-25")).click();

		GenUtils.sleepMillis(6000);// wait green message to disappear

		log.info("Check correct amount of items in cart");
		String expectedCartAmount = "(1)";
		String cartAmount = driver.findElement(By.xpath("//span[@class='cart-qty']")).getText();
		Assert.assertTrue(cartAmount.equals(expectedCartAmount),
				"Expected cart amount to be " + expectedCartAmount + " but received " + cartAmount + " instead.");

		log.info("Go to cart and confirm price");
		driver.findElement(By.cssSelector(".cart-label")).click();
		GenUtils.sleepMillis(3000);
		String cartPrice = driver.findElement(By.xpath("//span[@class='value-summary']/strong")).getText();
		Assert.assertTrue(price.equals(cartPrice),
				"Expected price is " + price + " but the price in the cart is " + cartPrice);

		log.info("Click on box verification if not already clicked");
		if (!driver.findElement(By.id("termsofservice")).isSelected())
			driver.findElement(By.id("termsofservice")).click();

		log.info("Click on 'checkout' button");
		driver.findElement(By.id("checkout")).click();
		GenUtils.sleepMillis(3000);

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

		log.info("Accept current shipping method");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.cssSelector(".shipping-method-next-step-button")).click();

		log.info("Accept current payment method");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.cssSelector(".payment-method-next-step-button")).click();

		log.info("Accept address confirmation");
		GenUtils.sleepMillis(2000);
		driver.findElement(By.cssSelector(".payment-info-next-step-button")).click();

		log.info("Check order total and confirm order");
		GenUtils.sleepMillis(2000);
		String checkoutPrice = driver.findElement(By.xpath("//span[@class='product-subtotal']")).getText();
		Assert.assertTrue(price.equals(checkoutPrice),
				"Expected price is " + price + " but the price on the checkout page is " + checkoutPrice);
		driver.findElement(By.cssSelector(".confirm-order-next-step-button")).click();

		log.info("Check that proper confirmation text has been received and click continue");
		GenUtils.sleepMillis(2000);
		String confirmText1 = "Thank you";
		String confirmText2 = "Your order has been successfully processed!";
		String receivedText1 = driver.findElement(By.xpath("//div[@class='page-title']/h1")).getText();
		String receivedText2 = driver.findElement(By.xpath("//div[@class='title']/strong")).getText();
		Assert.assertTrue(confirmText1.equals(receivedText1),
				"Expected text is " + confirmText1 + " but instead received " + receivedText1);
		Assert.assertTrue(confirmText2.equals(receivedText2),
				"Expected text is " + confirmText2 + " but instead received " + receivedText2);
		driver.findElement(By.cssSelector(".order-completed-continue-button")).click();

		log.info("Check that we've returned to the main page and that the cart is empty");
		GenUtils.sleepMillis(2000);
		String expectedMainPageText = "Welcome to our store";
		String receivedMainPageText = driver.findElement(By.xpath("//div[@class='topic-block-title']/h2")).getText();
		Assert.assertTrue(expectedMainPageText.equals(receivedMainPageText),
				"Expected to get " + expectedMainPageText + " but instead received " + receivedMainPageText);
		expectedCartAmount = "(0)";
		cartAmount = driver.findElement(By.xpath("//span[@class='cart-qty']")).getText();
		Assert.assertTrue(expectedCartAmount.equals(cartAmount),
				"Expected cart to be " + expectedCartAmount + " but received" + cartAmount);


	}

}
