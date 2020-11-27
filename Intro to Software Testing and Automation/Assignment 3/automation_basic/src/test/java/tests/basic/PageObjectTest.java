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

		price = app.pages().menusPage.clickLogin().ensurePageLoaded().setEmail(email).setPassword(password).clickLoginButton().goToApparelCategory().goToShoesCategory().rememberPrice();
		
		app.pages().shoesPage.goToAdidasShoesPage().addToCart().checkCart().goToCartPage().confirmPriceInCart().goToCheckoutPage().enterAddress().acceptShippingAndPaymentMethods().checkAndConfirmOrder(price).goToThankYouPage().verify().goToHomePage().checkThatCartIsEmpty();

	}

}
