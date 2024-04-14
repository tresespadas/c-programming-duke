void rotate(char matrix[10][10]){
	for (int i = 0; i < 10 / 2; i++) {
		for (int j = i; j < 10 - i - 1; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[10 - 1 - j][i];
			matrix[10 - 1 - j][i] = matrix[10 - 1 - i][10 - 1 - j];
			matrix[10 - 1 - i][10 - 1 - j] = matrix[j][10 - 1 - i];
			matrix[j][10 - 1 - i] = temp;
		}
	    }
}
