import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;
public class URLTitle {

    @Test
    void GetUrlAndTitle() throws InterruptedException {

        WebDriver driver = new EdgeDriver();

        // Open the browser with the given URL
        // This is for hyperlink on the home page
        String url = "https://www.promenauts.com/";
        driver.get(url);
        driver.manage().window().maximize();

        Thread.sleep(1000);

        String title = driver.getTitle();
        System.out.println("The Title Is: " + title);

        // ****** Get URL Functions ******

        String urlElement = driver.getCurrentUrl();
        System.out.println("The Current URL Is: " + urlElement);

        driver.close();
    }


}// class
