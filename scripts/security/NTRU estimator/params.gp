read("estimate.gp")

cbdMod3(k) = {
  my(p);
  p = floor(2^(2*k)/3);
  [p, p+1, p]/2^(2*k);
};


NTRUPLUS(n,q) = {
  coeffDist = cbdMod3(1);
  Run(n, n, q, coeffDist);
}



run() = {
  print("==================More NTRU+SIGN=========================="); 
  print("\n");
  print("=================NTRU+SIGN648========================");  
  NTRUPLUS(648,7129);
  print("\n");
  print("=================NTRU+SIGN972========================");  
  NTRUPLUS(972,9721);
  print("\n");
  print("=================NTRU+SIGN1296========================");  
  NTRUPLUS(1296,9721);
  print("\n");

}

run();
quit();
