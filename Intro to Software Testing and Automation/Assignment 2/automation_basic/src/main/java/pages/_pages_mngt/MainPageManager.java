package pages._pages_mngt;

import org.apache.log4j.Logger;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.PageFactory;

import applogic.ApplicationManager1;
import pages._pages_mngt.page_factory.DisplayedElementLocatorFactory;
import pages.super_pages.InternalPage;
import pages.super_pages.Page;
import pages.util_pages.LoginPage;
import util.ParamsUtils;
import util.SelUtils;

public class MainPageManager {

	private WebDriver driver;
	public SelUtils su;
	private Logger log;
	private ParamsUtils sessionParams;

	public InternalPage internalPage;
	public LoginPage loginPage;

	public MainPageManager(ApplicationManager1 app) {
		driver = app.getDriver();
		su = app.su;
		log = app.getLogger();
		sessionParams = app.getParamsUtils();

		loginPage = initElements(new LoginPage(this));
		internalPage = initElements(new InternalPage(this));

	}

	public <T extends Page> T initElements(T page) {
		// PageFactory.initElements(driver, page);
		// PageFactory.initElements(new AjaxElementLocatorFactory(driver, 10),
		// page);
		PageFactory.initElements(new DisplayedElementLocatorFactory(driver, 10), page);
		return page;
	}

	public WebDriver getWebDriver() {
		return driver;
	}

	public Logger gerLogger() {
		return log;
	}

	public ParamsUtils getSessionParams() {
		return sessionParams;
	}
}
