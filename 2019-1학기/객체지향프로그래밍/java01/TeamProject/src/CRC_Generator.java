class CRC { // CRC �ڷ���
	int value; // CRC �ڵ�
	int polynomial; // ���� CRC �߻� �ڵ�
}

public class CRC_Generator {
	// �Էµ� �����͸� CRC �ڵ�� ��ȯ���ִ� �޼ҵ�
	public static CRC toCRC(int data, int polynomial) { // KHJ
		int remainder = modulo_2_remainder(data, polynomial);
		
		CRC crc = new CRC();
		crc.value = (data << getBitSize(remainder)) | remainder;
		crc.polynomial = polynomial;
		return crc;
	}
	
	// CRC �ڵ�κ��� �� �����͸� ã�� �޼ҵ�
	public static int fromCRC(CRC crc) { // KDJ
		if (hasError(crc))
			return 0;
		return crc.value >>> (getBitSize(crc.polynomial)-1);
	}
	
	// CRC ���� �˻縦 �ϴ� �޼ҵ�
	public static boolean hasError(CRC crc) { // KHJ
		if (modulo_2_remainder(crc.value, crc.polynomial) == 0)
			return false;
		else
			return true;
	}
	
	// ����-2 ������ �������� ��ȯ�ϴ� �޼ҵ�
	public static int modulo_2_remainder(int data, int polynomial) { // KDJ
		int data_bitlen = getBitSize(data);
		int poly_bitlen = getBitSize(polynomial);
		int pivot, pin;
		
		// Operate modulo-2.
		for (pivot = data_bitlen-1; pivot > poly_bitlen-1; pivot--) {
			// pass if MSB equals 0
			if (getBit(data, pivot) == 0)
				continue;
			// do XOR
			for (pin = 0; pin < poly_bitlen; pin++) {
				// Bit Masking
				if (getBit(data, pivot-pin) != getBit(polynomial, poly_bitlen-1-pin))
					data |= (1 << pivot-pin); // �ش� ��Ʈ�� 1�� �ٲ�
				else
					data &= ~(1 << pivot-pin); // �ش� ��Ʈ�� 0���� �ٲ�
			}
		}
		return data;
	}
	
	// 2���������� ���� ���ϱ�
	public static int getBitSize(int x) {
		final int SIZE_OF_INT = 32;
		for (int i = SIZE_OF_INT-1; i >= 0; i--)
			if (getBit(x, i) == 1)
				return i+1;
		return 0;
	}
	
	// Ư�� �ڸ����� ��Ʈ�� �������� �޼ҵ�
	public static int getBit(int x, int index) {
		if ((x & (1 << index)) != 0)
			return 1;
		return 0;
	}

	// �Էµ� ������ 2������ ����ϴ� �޼ҵ�
	public static void printBit(int x) {
		final int SIZE_OF_INT = 32;
		for (int i = SIZE_OF_INT-1; i >= 0; i--) {
			if (getBit(x, i) == 0)
				System.out.print(0);
			else
				System.out.print(1);
			if (i % 8 == 0)
				System.out.print(" ");
		}
		System.out.println();
	}
	
	public static int parsePolynomial(String polyString) { // KOH
		// formated "3*x^3+x^2+1*x+3"
		int poly = 0;
		boolean hasCoeff, hasExp;
		int exp;
		
		// ���׽��� ���׽ĵ��� �迭�� �и��Ͽ�, �� ���׽��� �ؼ�
		String[] products = polyString.split("\\+");
		for (String prod : products) {
			// ����� �ִ��� �˻�
			hasCoeff = prod.contains("*");
			if (hasCoeff && Integer.parseInt(prod.split("\\*")[0]) % 2 == 0)
				continue; // ����� 0�̸� �Ѿ
			
			// ���� �˾Ƴ���
			hasExp = prod.contains("^");
			if (!hasExp) { // ������ ���� �Ǿ��� ���, x^0 Ȥ�� x^1
				exp = prod.contains("x") ? 1 : 0;
			}
			else {
				exp = Integer.parseInt(prod.split("\\^")[1]);
			}
			// ������ �ش��ϴ� ��Ʈ�� 1�� �ٲ�.
			poly |= (1 << exp);
		}
		return poly;
	}
	
	public static void main(String [] args) {
		int data = 0b11111010000; // ���� ������
		int poly = 0b1001; // ���� CRC �߻� �ڵ�
		CRC_Generator crcGen = new CRC_Generator();
		CRC crc = new CRC();
		crc = crcGen.toCRC(data, poly);
		
		crcGen.printBit(data);
		crcGen.printBit(crc.value);
		System.out.println(crcGen.hasError(crc));
		crcGen.printBit(crcGen.fromCRC(crc));
		
		int newPoly = crcGen.parsePolynomial("x^10+3*x^4+1+x+0*x^2+4*x^9");
		crcGen.printBit(newPoly);
	}
}
