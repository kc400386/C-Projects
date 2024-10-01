import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;

public class HyperLinks {

    @Test(priority = 1)
    void HyperlinkTest() throws InterruptedException { // Tests the links that takes you to amazon.

        WebDriver driver = new EdgeDriver();

        // Open the browser with the given URL
        // This is for hyperlink on the home page
        String url = "https://www.promenauts.com/";
        driver.get(url);
        driver.manage().window().maximize();

        Thread.sleep(2000);

        driver.findElement(By.xpath("//*[@id=\"h.4240120fc04a1eeb_4\"]/div/div/div/div/a/div[1]/p")).click();

        // Open the browser with the given URL
        // This is for hyperlink on the home page
        url = "https://www.promenauts.com/the-avarune-necklace";
        driver.get(url);
        driver.manage().window().maximize();

        Thread.sleep(2000);

        driver.findElement(By.xpath("//*[@id=\"yDmH0d\"]")).click();



        // Open the browser with the given URL
        // This is for first hyperlink on The Avarune Necklace page
        url = "https://www.promenauts.com/the-avarune-necklace";
        driver.get(url);
        driver.manage().window().maximize();

        Thread.sleep(2000);

        driver.findElement(By.xpath("//*[@id=\"yDmH0d\"]")).click();// Open the browser with the given URL


        // This is for the second hyperlink on The Avarune Necklace page
        url = "https://www.promenauts.com/the-avarune-necklace";
        driver.get(url);
        driver.manage().window().maximize();

        driver.findElement(By.xpath("//*[@id=\"h.60df39bd2d676c48_61\"]/div/div/div/div/a/div[1]/p")).click();

        driver.close();

    }// class


}//class
