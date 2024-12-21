for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) mx = max(mx, a[i][j]);
}

for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) mn = max(mn, a[i][j]);
}

for(int j=0;i<m;j++) {
      for(int i=0;i<n;i++) mx = max(mx, a[i][j]);
}

for(int j=0;i<m;j++) {
      for(int i=0;i<n;i++) mn = max(mn, a[i][j]);
}

