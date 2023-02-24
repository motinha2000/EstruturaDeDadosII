all: limpatela listasimples 

listasimples:
	@echo
	@echo =============================
	@echo 		LISTA SIMPLES
	@echo =============================
	@echo Compilando o programa Lista Simples
	gcc --std=c99 LinkedList.c LinkedList.h LinkedListTeste.c log.h log.c -o linkedlist
	@echo Tornando o arquivo executável
	chmod +x linkedlist
	@echo Executando o programa Lista Simples
	@echo ===================================
	@echo 
	./linkedlist

limpatela:
	@echo
	@echo ==========================
	@echo APAGANDO TODOS OS PROGRAMAS
	@echo ==========================
	@echo Removendo o programa ponteiro
	rm -f ponteiro
	@echo Removendo o programa ponteiro duplo
	rm -f ponteiro_duplo
	@echo Removendo o programa linkedlist
	rm -f linkedlist
	clear