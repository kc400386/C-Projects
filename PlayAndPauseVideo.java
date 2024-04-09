import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.edge.EdgeDriver;
import org.openqa.selenium.interactions.Actions;
import org.testng.annotations.Test;
import org.openqa.selenium.JavascriptExecutor;

public class PlayAndPauseVideo {

   @Test
    void PlayVideoAndPause() throws InterruptedException {

        WebDriver driver = new EdgeDriver();
        driver.manage().window().maximize();
        driver.get( "https://www.promenauts.com/");
        Thread.sleep(3000);

        // scrolls page down
       JavascriptExecutor scroll = (JavascriptExecutor) driver;
       scroll.executeScript("window.scroll(0,500)","");
       Thread.sleep(2000);

       //starts video
       WebElement local = driver.findElement(By.xpath("/html/body/div[1]/div/div[2]/div[3]/div/div[1]/section[4]/div[2]/div/div[3]/div/div/div[2]/div/div/div/div/div/a/div[1]/p"));
       Actions VidStart = new Actions(driver);
       VidStart.moveToElement(local).moveByOffset(0, 200).click().perform();
       Thread.sleep(5000);

       //stops video
       WebElement localTwo = driver.findElement(By.xpath("/html/body/div[1]/div/div[2]/div[3]/div/div[1]/section[4]/div[2]/div/div[3]/div/div/div[2]/div/div/div/div/div/a/div[1]/p"));
       Actions VidStop = new Actions(driver);
       VidStop.moveToElement(localTwo).moveByOffset(0, 200).click().perform();
       Thread.sleep(3000);

       driver.close();

   }// end PlayVideoAndPause
}// class
