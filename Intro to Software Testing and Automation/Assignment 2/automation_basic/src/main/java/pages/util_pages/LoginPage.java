package pages.util_pages;

import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.ui.ExpectedConditions;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.AnyPage;
import pages.super_pages.InternalPage;

public class LoginPage extends AnyPage {

	public LoginPage(MainPageManager pages) {
		super(pages);
	}

	@FindBy(id = "username")
	private WebElement usernameField;

	@FindBy(id = "password")
	private WebElement passwordField;

	@FindBy(xpath = "//input[@type='submit']")
	private WebElement submitButton;

	@FindBy(id = "login_page")
	private WebElement loginPageBody;


	public LoginPage setUsernameField(String text) {
		log.info("Username for login is: " + text);
		usernameField.sendKeys(text);
		return this;
	}

	public LoginPage setPasswordField(String text) {
		log.info("Password for login is: " + text);
		passwordField.sendKeys(text);
		return this;
	}

	public InternalPage clickSubmit() {
		submitButton.click();
		log.info("Clicked submit button.");
		return pages.internalPage.ensurePageLoaded();
	}


	public LoginPage ensurePageLoaded() {
		super.ensurePageLoaded();
		waitBig.until(ExpectedConditions.visibilityOf(loginPageBody));
		return this;
	}
}
