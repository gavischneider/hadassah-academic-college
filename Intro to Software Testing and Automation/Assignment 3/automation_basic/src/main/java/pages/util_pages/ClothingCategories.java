package util;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class ClothingCategories extends MenusPage {

	public ClothingCategories(MainPageManager pages) {
		super(pages);
		// TODO Auto-generated constructor stub
	}
	
	public ClothingCategories ensurePageLoaded() {
		 super.ensurePageLoaded();
		   
		 waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.linkText("Shoes"))));
		   
		 return this;
	}
	
	public ShoesPage goToShoesCategory() {
		log.info("Go to the 'Shoes' category");
		driver.findElement(By.linkText("Shoes")).click();
		GenUtils.sleepMillis(2000);
		
		return pages.shoesPage.ensurePageLoaded();
	}

	

}
