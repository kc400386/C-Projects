import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;
import org.openqa.selenium.JavascriptExecutor;

public class MaximizeScrollExit {

    @Test
    void MaximizeAndScroll() throws InterruptedException {

        WebDriver driver = new EdgeDriver();

        // Open the browser with the given URL
        // This is for hyperlink on the home page
        String url = "https://www.promenauts.com/the-avarune-necklace";
        driver.get(url);
        driver.manage().window().maximize();

        Thread.sleep(3000);

        JavascriptExecutor exe = (JavascriptExecutor) driver;

        exe.executeScript("window.scroll(0,1000)","");

        driver.close();

    }


}// class
