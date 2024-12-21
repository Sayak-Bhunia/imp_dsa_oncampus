for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
            // Check if the current element is on the boundary
          if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) sum += matrix[i][j];
    }
}
