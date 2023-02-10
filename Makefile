all: clean ponteiro ponteiro_duplo

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
	rm -f ponteiro_duplo

ponteiro_duplo:
	@echo
	@echo =============================
	@echo 		PONTEIRO DUPLO
	@echo =============================
	@echo Compilando o programa Ponteiro Duplo
	gcc ponteiro_duplo.c -o ponteiro_duplo
	@echo Tornando o arquivo executável
	chmod +x ponteiro_duplo
	@echo Executando o programa Ponteiro Duplo
	@echo =============================================
	@echo 
	./ponteiro_duplo