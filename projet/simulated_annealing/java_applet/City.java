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
 * This class implements a city that must be visited.
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

class City {

  /**
   * The city's x position.
   */
  private int xpos;

  /**
   * The city's y position.
   */
  private int ypos;

  /**
   * Constructor.
   *
   * @param x The city's x position
   * @param y The city's y position.
   */
  public City(int x, int y) {
    xpos = x;
    ypos = y;
  }

  /**
   * Return's the city's x position.
   *
   * @return The city's x position.
   */
  public int getx() {
    return xpos;
  }

  /**
   * Returns the city's y position.
   *
   * @return The city's y position.
   */
  public int gety() {
    return ypos;
  }

  /**
   * Returns how close the city is to another city.
   *
   * @param cother The other city.
   * @return A distance.
   */
  public int proximity(City cother) {
    return proximity(cother.getx(),cother.gety());
  }

  /**
   * Returns how far this city is from a a specific point.
   * This method uses the pythagorean theorum to calculate
   * the distance.
   *
   * @param x The x coordinate
   * @param y The y coordinate
   * @return The distance.
   */
  public int proximity(int x, int y) {
    int xdiff = xpos - x;
    int ydiff = ypos - y;
    return(int)Math.sqrt( xdiff*xdiff + ydiff*ydiff );
  }
}
