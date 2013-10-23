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
 * This class implements SimulatedAnnealing.
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
public class SimulateAnnealing extends Thread {

  /**
   * The TravelingSalesman object that owns this object.
   */
  protected SimulatedAnnealingClient owner;

  /**
   * The current temperature.
   */
  protected double temperature;

  /**
   * The length of the current path.
   */
  protected double pathlength;

  /**
   * The length of the best path.
   */
  protected double minimallength;

  /**
   * The current order of cities.
   */
  protected int order[];

  /**
   * The best order of cities.
   */
  protected int minimalorder[];

  /**
   * Constructor
   *
   * @param owner The TravelingSalesman class that owns this object.
   */
  SimulateAnnealing(SimulatedAnnealingClient owner)
  {
    this.owner = owner;
    order = new int[owner.getCount()];
    minimalorder = new int[owner.getCount()];
  }

  /**
   * Called to determine if annealing should take place.
   *
   * @param d The distance.
   * @return True if annealing should take place.
   */
  public boolean anneal(double d)
  {
    if (temperature < 1.0E-4) {
      if (d > 0.0)
        return true;
      else
        return false;
    }
    if (Math.random() < Math.exp(d / temperature))
      return true;
    else
      return false;
  }



  /**
   * Used to ensure that the passed in integer is within thr city range.
   *
   * @param i A city index.
   * @return A city index that will be less than CITY_COUNT
   */
  public int mod(int i)
  {
    return i % owner.getCount();
  }







  /**
   * Run as a background thread. This method is called to
   * perform the simulated annealing.
   */
  public void run()
  {
    int cycle=1;
    int sameCount = 0;
    temperature = owner.getStartingTemperature();

    initorder(order);
    initorder(minimalorder);

    pathlength = length();
    minimallength = pathlength;


    while (sameCount<50) {
      // update the screen
      owner.update();
      owner.setStatus("Cycle=" + cycle + ",Length=" + minimallength + ",Temp=" + temperature );

      // make adjustments to city order(annealing)
      for (int j2 = 0; j2 < owner.getCount() * owner.getCount(); j2++) {
        int i1 = (int)Math.floor((double)owner.getCount() * Math.random());
        int j1 = (int)Math.floor((double)owner.getCount() * Math.random());
        double d = owner.getError(i1, i1 + 1) + owner.getError(j1, j1 + 1) - owner.getError(i1, j1) - owner.getError(i1 + 1, j1 + 1);
        if (anneal(d)) {
          if (j1 < i1) {
            int k1 = i1;
            i1 = j1;
            j1 = k1;
          }
          for (; j1 > i1; j1--) {
            int i2 = order[i1 + 1];
            order[i1 + 1] = order[j1];
            order[j1] = i2;
            i1++;
          }
        }
      }

      // See if this improved anything
      pathlength = length();
      if (pathlength < minimallength) {
        minimallength = pathlength;
        for (int k2 = 0; k2 < owner.getCount(); k2++)
          minimalorder[k2] = order[k2];
        sameCount=0;
      } else
        sameCount++;
      temperature = owner.getDelta() * temperature;
      cycle++;
    }

    // we're done
    owner.setStatus("Solution found after " + cycle + " cycles." );
  }

  /**
   * Return the length of the current path through
   * the cities.
   *
   * @return The length of the current path through the cities.
   */
  public double length()
  {
    double d = 0.0;
    for (int i = 1; i <= owner.getCount(); i++)
      d += owner.getError(i, i - 1);
    return d;
  }

  /**
   * Set the specified array to have a list of the cities in
   * order.
   *
   * @param an An array to hold the cities.
   */
  public void initorder(int an[])
  {
    for (int i = 0; i < owner.getCount(); i++)
      an[i] = i;
  }
}