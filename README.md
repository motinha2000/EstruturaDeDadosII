# Estrutura de Dados II 2023/1

Repositório da Disciplina Estrutura de dados II

# Instalação 

. Instalação do git
. Abra o terminal e clone o repositório

```code
  . git clone https://github.com/motinha2000/EstruturaDeDadosII.git
```

. Para criar o diretorio
	.mkdir git
. Para acessar o diretorio
	.cd git
. Para configurar credenciais usar os comandos
	. git config --global user.name "SEU NOME"
	. git config --global user.email "SEU EMAIL"

.Para puxar a versão mais recente da nuvem 
	.git pull

. Para adicionar mudanças nos arquivos
	.git add

. Para comitar uma alteração local para a nuvem
	.git commit -m "MENSAGEM"
	.git push

### COMANDOS ADICIONAIS

git status
notepad "NOME DO ARQUIVO"
more "NOME DO ARQUIVO"
git log
git log --oneline
git show "versão"
git checkout "versão"

#### OBS

Nem sempre o git abre o navegador para continuar a autenticação de credenciais ele pode abrir por prompt. Usar:
EMAIL
TOKEN - Github>Foto de perfil>Settings>UltimoDeveloper Settings>Personal access tokens> Tokens(classic) 
-> Generation New Token Classic > Selecionar expiração> ilimitada> escopo> repo