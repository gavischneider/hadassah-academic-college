package pages.super_pages;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.ui.ExpectedConditions;

import pages._pages_mngt.MainPageManager;
import pages.util_pages.LoginPage;

public class InternalPage extends AnyPage {

	@FindBy(id = "logout")
	private WebElement logoutLink;

	public InternalPage(MainPageManager pages) {
		super(pages);
	}

	public InternalPage ensurePageLoaded() {
		super.ensurePageLoaded();

		waitBig.until(ExpectedConditions.presenceOfElementLocated(By.cssSelector("body")));
		return this;
	}

	public LoginPage logout() {
		log.debug("Logout");
		logoutLink.click();

		return pages.loginPage.ensurePageLoaded();

	}



}