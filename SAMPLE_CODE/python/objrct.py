"#!/usr/bin/env python3.5"
import matplotlib.pyplot as plt
"""
%matplotlib inline  
"""
class circle(object):
	def __init__(self,radius,colour):
		self.radius=radius;
		self.colour=colour;

	def add_radius(self,r):
		self.radius=self.radius+r;
		return(self.radius)

	def drawcircle(self):
		plt.gca().add_patch(plt.Circle((0, 0), radius=self.radius, fc=self.colour))
		plt.axis('scaled')
		plt.show()


red = circle(3,"grey")
print(red.radius)
print(red.colour)
red.drawcircle() 
