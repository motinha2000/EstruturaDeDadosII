all: clean ponteiro

ponteiro:
	@echo
	@echo =============================
	@echo 		PONTEIRO SIMPLES
	@echo =============================
	@echo Compilando o programa Ponteiros
	gcc ponteiro.c -o ponteiro
	@echo Tornando o arquivo executável
	chmod +x ponteiro
	@echo Executando o programa Ponteiros
	@echo =============================================
	@echo 
	./ponteiro
	
clean:
	@echo
	@echo ========================================
	@echo 		APAGANDO TODOS OS PROGRAMAS
	@echo ========================================
	@echo Removendo o programa ponteiro
	rm -f ponteiro