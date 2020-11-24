package pages.util_pages;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.testng.Assert;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class RegisterSuccessPage extends MenusPage {

	public RegisterSuccessPage(MainPageManager pages) {
		super(pages);
	}

	@FindBy(name = "register-continue")
	private WebElement continueButton;

	private final static String SUCCESS_MESSAGE = "Your registration completed";

	public RegisterSuccessPage ensurePageLoaded() {
		super.ensurePageLoaded();
		waitBig.until(ExpectedConditions.visibilityOf(continueButton));
		return this;
	}

	public RegisterSuccessPage verifySuccessMessage() {
		log.info("Verify message: " + SUCCESS_MESSAGE);
		String actualTextRegistration = driver.findElement(By.cssSelector(".result")).getText();

		Assert.assertTrue(actualTextRegistration.equals(SUCCESS_MESSAGE),
				"Expected value: '" + SUCCESS_MESSAGE + "', but actual is '" + actualTextRegistration + "'");
		return this;
	}

	public HomePage clickContinue() {
		continueButton.click();
		return pages.homePage.ensurePageLoaded();
	}

}
