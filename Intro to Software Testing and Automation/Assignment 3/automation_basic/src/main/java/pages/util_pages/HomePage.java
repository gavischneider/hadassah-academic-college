package pages.util_pages;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.testng.Assert;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class HomePage extends MenusPage {

	public HomePage(MainPageManager pages) {
		super(pages);
	}

	private final static String HOME_MESSAGE = "Welcome to our store";

	public HomePage ensurePageLoaded() {
		super.ensurePageLoaded();
		waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.cssSelector(".topic-block-title > h2"))));
		return this;
	}

	public HomePage verifyHomeText() {
		String actualMessage = driver.findElement(By.cssSelector(".topic-block-title > h2")).getText();

		Assert.assertTrue(actualMessage.equals(HOME_MESSAGE),
				"Expected value: '" + HOME_MESSAGE + "', but actual is '" + actualMessage + "'");
		return this;
	}
	
	public void checkThatCartIsEmpty() {
		String expectedMainPageText = "Welcome to our store";
		String receivedMainPageText = driver.findElement(By.xpath("//div[@class='topic-block-title']/h2")).getText();
		Assert.assertTrue(expectedMainPageText.equals(receivedMainPageText),
				"Expected to get " + expectedMainPageText + " but instead received " + receivedMainPageText);
		String expectedCartAmount = "(0)";
		String cartAmount = driver.findElement(By.xpath("//span[@class='cart-qty']")).getText();
		Assert.assertTrue(expectedCartAmount.equals(cartAmount),
				"Expected cart to be " + expectedCartAmount + " but received" + cartAmount);
	}

}
