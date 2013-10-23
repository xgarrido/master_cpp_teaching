import java.applet.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Simulated Annealing and the Traveling Salesman
 * Copyright 2005 by Heaton Research, Inc.
 * by Jeff Heaton (http://www.heatonresearch.com) 12-2005
 * -------------------------------------------------
 * This source code is copyrighted.
 * You may reuse this code in your own compiled projects.
 * However, if you would like to redistribute this source code
 * in any form, you must obtain permission from Heaton Research.
 * (support@heatonresearch.com).
 * -------------------------------------------------
 *
 * This class implements the view of the path of cities.
 *
 * -------------------------------------------------
 * Want to learn more about Neural Network Programming in Java?
 * Have a look at our e-book:
 *
 * http://www.heatonresearch.com/articles/series/1/
 *
 * @author Jeff Heaton (http://www.jeffheaton.com)
 * @version 1.0
 */
public class TravelingSalesman extends Applet implements
    SimulatedAnnealingClient
{
  /**
   * The cities to be visited.
   */
  private City cities[];

  /**
   * The simulated annealing worker class.
   */
  private SimulateAnnealing worker;

  /**
   * The Start button.
   */
  private Button ctrlStart;

  /**
   * The TextField that holds the number of cities.
   */
  private TextField ctrlCities;

  /**
   * The TextField for the starting temperature.
   */
  private TextField ctrlTemp;

  /**
   * The TextField for the delta value.
   */
  private TextField ctrlDelta;

  /**
   * Holds the buttons and other controls, forms a strip across
   * the bottom of the applet.
   */
  private Panel ctrlButtons;

  /**
   * Has the thread been started?
   */
  private boolean started;

  /**
   * The current status, which is displayed just above the controls.
   */
  private String status = "";

  /**
   * The init method, sets up the applet.
   */
  public void init()
  {
    setLayout(new BorderLayout());

    // setup the controls
    ctrlButtons = new Panel();
    ctrlStart = new Button("Start");
    ctrlButtons.add(ctrlStart);
    ctrlButtons.add(new Label("# Cities:"));
    ctrlButtons.add(ctrlCities = new TextField(5));
    ctrlButtons.add(new Label(",Temp:"));
    ctrlButtons.add(ctrlTemp = new TextField(5));
    ctrlButtons.add(new Label(",Delta:"));
    ctrlButtons.add(ctrlDelta = new TextField(5));
    this.add(ctrlButtons, BorderLayout.SOUTH);

    // set the default values
    ctrlTemp.setText("100");
    ctrlDelta.setText("0.99");
    ctrlCities.setText("100");

    // add an action listener for the button
    ctrlStart.addActionListener(new ActionListener()
    {

      public void actionPerformed(ActionEvent arg0)
      {
        System.out.println(arg0.getActionCommand());
        startThread();

      }
    });

    started = false;
    update();
  }

  /**
   * Called when the applet should be repainted.
   *
   * @param g The Graphics object used to paint.
   */
  public void paint(Graphics g)
  {
    update();
  }

  /**
   * Called to get the number of cities.
   *
   * @return The number of cities.
   */
  public int getCount()
  {
    return cities.length;
  }

  /**
   * Returns the distance between two cities.
   *
   * @param i The first city.
   * @param j The second city.
   * @return The distance between the two cities.
   */
  public double getError(int i, int j)
  {

    int c1 = worker.order[i % cities.length];
    int c2 = worker.order[j % cities.length];
    return cities[c1].proximity(cities[c2]);
  }

  /**
   * Returns the starting temperature for the
   * annealing process.
   *
   * @return The starting temperature for the annealing process.
   */
  public double getStartingTemperature()
  {
    double result;
    try
    {
      result = new Double(ctrlTemp.getText()).doubleValue();
    } catch (NumberFormatException e)
    {
      result = 10;
    }
    return result;
  }

  /**
   * Called to determine if annealing should take place.
   *
   * @param d The distance.
   * @return True if annealing should take place.
   */
  public double getDelta()
  {
    double result;
    try
    {
      result = new Double(ctrlDelta.getText()).doubleValue();
    } catch (NumberFormatException e)
    {
      result = 10;
    }
    return result;
  }

  /**
   * Called to determine if annealing should take place.
   *
   * @param d The distance.
   * @return True if annealing should take place.
   */
  public void update()
  {
    Image img = createImage(getBounds().width, getBounds().height);
    Graphics g = img.getGraphics();

    int width = getBounds().width;
    int height = getBounds().height;

    g.setColor(Color.white);
    g.fillRect(0, 0, width, height);

    if (cities != null)
    {

      g.setColor(Color.blue);
      for (int i = 0; i < cities.length; i++)
      {
        int xpos = cities[i].getx();
        int ypos = cities[i].gety();
        g.fillOval(xpos - 5, ypos - 5, 10, 10);
      }

      g.setColor(Color.red);

      for (int i = 0; i < cities.length; i++)
      {
        int icity = worker.minimalorder[i];
        if (i != 0)
        {
          int last = worker.minimalorder[i - 1];

          g.drawLine(cities[icity].getx(), cities[icity].gety(), cities[last]
              .getx(), cities[last].gety());
        }
      }
    }

    FontMetrics fm = g.getFontMetrics();
    g.drawString(status, 0, ctrlButtons.getBounds().y - fm.getHeight());

    getGraphics().drawImage(img, 0, 0, this);

  }

  /**
   * Called to determine if annealing should take place.
   *
   * @param d The distance.
   * @return True if annealing should take place.
   */
  public void setStatus(String status)
  {
    this.status = status;
  }

  /**
   * Start the background thread.
   */
  public void startThread()
  {
    // get the number of cities
    int numCities = 50;
    try
    {
      numCities = Integer.parseInt(ctrlCities.getText());
    } catch (NumberFormatException e)
    {
    }

    // create a random list of cities

    cities = new City[numCities];
    for (int i = 0; i < numCities; i++)
    {
      cities[i] = new City((int) (Math.random() * (getBounds().width - 10)),
          (int) (Math.random() * (getBounds().height - 80)));
    }

    started = true;

    // start up the background thread

    if (worker != null)
      worker = null;
    worker = new SimulateAnnealing(this);
    worker.setPriority(Thread.MIN_PRIORITY);
    worker.start();
    update();
  }

}
