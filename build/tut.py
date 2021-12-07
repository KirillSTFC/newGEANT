import sys
import ROOT as rt
import numpy as np
import matplotlib.pyplot as plt
from array import array

nscans = 15
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MERGING FILES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
for x in range (nscans):
    ch = rt.TChain("Photons")
    ch.Add("Energy%s_t0.root" %str(x));
    ch.Add("Energy%s_t1.root" %str(x));
    ch.Add("Energy%s_t2.root" %str(x));
    ch.Add("Energy%s_t3.root" %str(x));
    ch.Add("Energy%s_t4.root" %str(x));
    ch.Add("Energy%s_t5.root" %str(x));
    ch.Add("Energy%s_t6.root" %str(x));
    ch.Add("Energy%s_t7.root" %str(x));
    ch.Merge("Energy%s.root" %str(x));
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

#---------------------------------------ROOT PLOT EXAMPLE---------------------------------------------------#
f = rt.TFile("Energy3.root")
myTree = f.Get("Photons")
c1=rt.TCanvas()
c1.cd(1)
histo=rt.TH1F("histo","", 20,-10,10)
myTree.Draw("fX>>histo")
c1.Print("c1.pdf")
plt.show()
#---------------------------------------MATPLOTLIB PLOT EXAMPLE---------------------------------------------------#
n_bins=20;
f = rt.TFile("Energy3.root")
myTree = f.Get("Photons")
xarray=[]
for i in myTree:
     events = i.fX
     xarray.append(events)
print(xarray)
plt.hist(xarray, bins=n_bins)
plt.show()
