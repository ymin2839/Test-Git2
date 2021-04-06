#include "pch.h"
#include "MsZip.h"

void CMsZip::OnBnClickedDecompressBtn()
{
	int file_size = 0;
	// 압축을 해제할 파일인 'test.___' 파일에서 파일 내용을 복사해서 가져온다.
	// 이때 파일의 크기는 file_size에 저장된다.
	char* p_data = ReadDataFromFile(L"test.___", &file_size);
	// 지정된 파일의 내용이 있고 그 내용을 읽은 경우!
	if (p_data != NULL) {
		DECOMPRESSOR_HANDLE decompressor;
		unsigned long decompressed_size = 0;
		// 압축을 해제할 객체를 생성한다. 압축 알고리즘은 MSZIP을 사용한다.
		if (CreateDecompressor(COMPRESS_ALGORITHM_MSZIP, NULL, &decompressor)) {
			// 압축이 해제된 내용을 저장하려면 압축이 해제된 크기를 알아야 하기 때문에 
			// 네 번째 인자에 NULL 그리고 다섯 번째 인자에 0을 넣고 압축 해제 함수를 실행하면
			// 함수가 실패하면서 여섯 번째 인자에 압축을 해제했을 때 크기가 저장된다.
			if (0 == Decompress(decompressor, p_data, file_size, NULL, 0, &decompressed_size)) {
				// 압축이 해제되었을 때 크기를 제대로 얻는 경우!
				if (decompressed_size > 0) {
					// 압축이 해제된 데이터를 저장하기 위해 메모리를 할당한다.
					char* p_decompress_data = new char[decompressed_size];
					// p_data에 있는 내용을 압축해제하여 p_decompress_data에 저장한다.
					if (Decompress(decompressor, p_data, file_size,
						p_decompress_data, decompressed_size, &decompressed_size)) {
						// p_decompress_data에 저장된 데이터를 파일에 저장한다.
						SaveDataToFile(L"unzip_test.bmp", p_decompress_data, decompressed_size);
					}
					// 압축이 해제된 데이터를 저장하기 위해 할당한 메모리를 해제한다.
					delete[] p_decompress_data;
				}
			}
			// 압축 해제를 위해 만든 객체를 제거한다.
			CloseCompressor(decompressor);
		}
		// 파일의 내용을 저장하기 위해 할당한 메모리를 해제한다.
		delete[] p_data;
	}
}
