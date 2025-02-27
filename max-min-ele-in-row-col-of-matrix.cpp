for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) mx = max(mx, a[i][j]);
}

for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) mn = min(mn, a[i][j]);
}

for(int j=0;j<m;j++) {
      for(int i=0;i<n;i++) mx = max(mx, a[i][j]);
}

for(int j=0;j<m;j++) {
      for(int i=0;i<n;i++) mn = min(mn, a[i][j]);
}

