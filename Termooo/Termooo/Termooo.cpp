// Termooo.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include<iostream>
#include<windows.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<random>
#include<stdio.h>
using namespace std;

typedef enum {
	BLACK, BLUE, GREEN, YELLOW, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
	LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, CYAN, WHITE
} COLORS;

constexpr int MIN = 0;
constexpr int MAX = 999;

static int __BACKGROUND = 1;
static int __FOREGROUND = LIGHTGRAY;
static string bd[1000] = { "sagaz","amago","negro","exito","mexer","termo","senso","nobre","algoz","afeto","plena","etica","mutua","tenue",
"sutil","vigor","aquem","audaz","porem","fazer","sanar","secao","inato","assim","cerne","ideia","desde","fosse","poder","moral","torpe",
"honra","muito","justo","futil","gozar","anexo","razao","quica","etnia","sobre","icone","tange","egide","sonho","lapso","mutuo","expor",
"haver","habil","amigo","casal","tempo","seara","pesar","posse","avido","entao","bocal","dengo","genro","coser","ardil","porra","corja",
"prole","causa","paria","detem","dizer","tenaz","dever","digno","crivo","saber","obice","apice","ansia","ceder","animo","brado","graca",
"gleba","orgia","comum","assaz","atroz","culto","sendo","temor","mundo","censo","pauta","fugaz","denso","valha","cozer","ainda","nenem",
"vicio","forte","estar","reves","vulgo","pudor","regra","dogma","louco","criar","banal","impor","pifio","tenro","desse","apraz","jeito",
"round","ordem","saude","atras","pedir","reaca","clava","merce","viril","usura","juizo","sabio","prosa","manso","servo","ontem","feliz",
"presa","coisa","falar","homem","cunho","forma","fluir","afago","devir","ebrio","meiga","plato","serio","vendo","xibiu","guisa","mesmo",
"pleno","limbo","temer","visar","magoa","cisma","bruma","heroi","acaso","puder","exodo","lugar","valor","gerar","obvio","afins","obter",
"impio","matiz","crise","praxe","senil","certo","havia","venia","fluxo","enfim","posso","ritmo","alibi","tedio","todos","tomar","garbo",
"reter","uniao","pulha","parvo","valia","abrir","visao","grato","vital","favor","vivaz","bravo","laico","facil","parco","prumo","FALSO",
"genio","ameno","possa","olhar","reles","obito","prime","burro","levar","tesao","tecer","casta","selar","anelo","fator","legal","ranco",
"citar","rogar","farsa","facam","adiar","nocao","achar","coeso","morte","cisao","epico","cabal","sabia","nicho","imune","falta","fardo",
"sinto","ativo","forca","gente","ouvir","exato","viver","haste","amplo","lavra","brega","sulco","sonso","passo","dubio","noite","gesto",
"labor","cesta","revel","sesta","tendo","leigo","unico","deter","vemos","arduo","atuar","feixe","rever","calma","vadia","otica","humor",
"ciume","igual","tende","pobre","toada","hiato","sonsa","debil","ideal","ponto","vacuo","velho","outro","claro","ambos","terno","remir",
"fusao","varao","linda","carma","cauda","probo","leito","senao","advem","doido","ajuda","marco","horda","jovem","fonte","inata","capaz",
"xeque","relva","tenra","algum","cacar","ficar","velar","anuir","apoio","serie","farao","terra","rigor","dorso","vimos","verso","vazio",
"lider","tanto","botar","entre","frase","cocar","prece","cruel","massa","mocao","virus","morar","ambas","pouco","peste","coesa","casto",
"sente","signo","fauna","covil","preso","faina","credo","minha","feito","furor","raiva","docil","lazer","impar","vetor","ciclo","flora",
"torco","arido","maior","chata","aceso","brisa","papel","corno","beata","vulto","trama","houve","pegar","breve","birra","vasto","liame",
"manha","setor","adeus","salvo","senda","ardor","seita","banzo","morro","blase","nossa","pecha","atomo","visse","prado","livro","reger",
"antro","avaro","peixe","segue","comer","plano","prono","ocaso","meses","rezar","saiba","ancia","sorte","chuva","aureo","saida","otimo",
"alias","nunca","pajem","acima","junto","chulo","foder","mudar","fitar","opcao","serao","jazia","fruir","sinal","parar","treta","carro",
"puxar","seria","fugir","bando","nacao","motim","gerir","prazo","andar","tosco","grupo","alude","leite","norma","sinha","epoca","brava",
"rapaz","tenso","lenda","exame","arcar","aviao","idolo","parte","venal","campo","tirar","soldo","reino","psico","malta","praga","quota",
"virao","sumir","vilao","exijo","aonde","anais","logro","pompa","traga","corpo","preto","fixar","voraz","agora","antes","quase","cheio",
"certa","risco","turva","nodoa","solto","copia","praia","oasis","turba","filho","alado","indio","apego","messe","caixa","parva","texto",
"estao","grave","doido","prova","acesa","verve","perda","nivel","apelo","ligar","pardo","tocar","fenda","trupe","atrio","lindo","retem",
"viria","sabia","dessa","alcar","coito","livre","navio","opaco","ficha","aurea","conta","fraco","etico","verbo","afora","astro","faixa",
"elite","supra","parca","verba","cioso","glosa","autor","lidar","jirau","mente","tinha","firme","grata","oxala","fatos","festa","magia",
"bater","calda","fatal","prive","cousa","reses","junco","irmao","pique","deixa","molho","pagao","douto","salve","macio","abriu","turvo",
"torso","supor","atual","light","bicho","igneo","asilo","posto","manha","orfao","rouca","extra","caber","curso","judeu","sarca","sexta",
"locus","besta","vezes","ruina","desta","pisar","zelar","radio","paira","abuso","video","ereto","finda","combo","porta","bioma","longe",
"vinha","culpa","agudo","canon","feudo","vosso","menos","baixo","facto","tetra","urgia","advir","cutis","surja","bonus","meigo","estio",
"traco","drops","super","sitio","autos","tento","rumor","gosto","cocho","facho","suave","pilar","museu","clean","amena","calao","lasso",
"turma","geral","acola","optar","acões","medir","chama","pifia","nosso","boato","penta","mosto","louca","podio","rubro","lapis","crime",
"local","letal","hobby","pacto","ponha","folga","cover","cacho","refem","drama","brabo","hoste","aroma","vetar","vigia","fazia","pasmo",
"poema","feroz","acude","finjo","rival","movel","mesma","troca","axila","monte","golpe","peito","ecoar","metie","aluno","avida","pareo",
"coral","riste","lesse","forum","plebe","licao","teste","daqui","sucia","forem","monge","clima","carta","chato","ebano","poeta","escol",
"cetro","macro","viram","julia","falha","sarau","venha","passa","swing","briga","ateia","piada","tacha","conto","legua","farta","cargo",
"calmo","atimo","verde","perco","fruto","berro","plaga","busca","tarde","idoso","roupa","plumo","aviso","virar","vento","corso","chefe",
"tribo","broxa","arado","grama","assar","surto","estro","civil","seixo","recem","bruta","catre","traje","artur","ornar","saldo","impia",
"deste","nuvem","beijo","fosso","deram","troca","pedra","vedar","trato","arfar","depor","ticao","porte","irado","grota","uteis","canso",
"ambar","giria","pasma","silvo","cifra","casar","bazar","gabar","manga","amado","unica","benca","regio","manga","sosia","magna","vazao",
"tutor","rural","pavor","laudo","segar","tiver","bruto","perto","bucho","itens","renda","troco","midia","tchau","nesse","vagar","molde",
"minar","jejum","odiar","lesto","viado","clero","amiga","vadio","inter","fossa","meche","feita","orgao","sotao","aviar","areia","pomar",
"negar","cenho","paiol","largo","cinto","ileso","lesao","canto","rocha","pugna","visto","horto","ruido","podar","proto","bolsa","inves",
"pinho","urdir","marca","civel","vista","densa","ufano","frota","dubia","guria","morfo","mocho","jogar","vasta","penso","bulir","xucro",
"close","umido","piche","culta","mamae","peita","esgar","canil","bunda","cheia","chula","linha","resto","amada","apear","ubere","stand",
"varoa","misto","fazes","demao","natal","manto","monta","narco","findo","fundo","campa","barao","gemer","agape","nessa","chaga","jazer",
"simio","tenha","retro","album","mover","preco","cerca","venho","folia","ardis","cosmo","labia","punha","polis","sabor","alamo","seiva",
"sigla","porca","velha","matar","calca","santo","banto","letra","ferpa","verao","volta","rente","louro","firma","ceita","salva","barro",
"arroz","etapa","tumba","axial","nesta","torna","redor","miope","limpo","trago","audio","coevo","troco","bolso","enjoo","solta","ousar",
"final","sinta","lousa","lutar","fugiu","zumbi","baixa","corar","queda","mimar","obtem","farol","coroa","cacto","veloz","logos","neste",
"nacar","reler","fatuo","burra","folha","penca","longo","vario","vazia","danca","quite","forro","macho","mania","farto","justa","sugar",
"puido","bedel","staff","ultra","repor","lucro","refil","viger","salmo","subir","chave","gueto","passe","custo","calor","sexto","urgir",
"sadio","mimos","harem","hifen","valer","logia","versa","usual","mouro","socio","lento","todas","cardo","calvo","redea","anzol","ardua",
};

void textcolor(int letras, int fundo) {
	__FOREGROUND = letras;
	__BACKGROUND = fundo;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		letras + (__BACKGROUND << 4));
}

int main(int argc,char *argv[]) {
	int repetir = 0;
	do {
		random_device rd;
		default_random_engine eng(rd());
		uniform_int_distribution<int> distr(MIN, MAX);
		int nr = distr(eng);
		cout << "seed: " << nr;
		string palDia = bd[nr];
		string palDig;
		char rep;
		int placar = 0;

		cout << "\n-- Wordle do Picole --\n";
		cout << "[ ] [ ] [ ] [ ] [ ] - Digite: ";
		for (int i = 0;i < 5;i++) {
			cin >> palDig;

			if (palDig.length() > 5 || palDig.length() < 5) {
				cout << "Palavra com mais ou menos de 5 letras";
			}
			else {
				for (int w = 0;w < 5;w++) {
					if ((palDia.find(palDig[w]) != string::npos) && palDig[w] == palDia[w]) {
						textcolor(2, 0);
						cout << "[" << palDig[w] << "] ";
						textcolor(7, 0);
						placar++;
					}
					else if ((palDia.find(palDig[w]) != string::npos) && palDig[w] != palDia[w]) {
						textcolor(6, 0);
						cout << "[" << palDig[w] << "] ";
						textcolor(7, 0);
						placar = 0;
					}
					else {
						cout << "[" << palDig[w] << "] ";
						textcolor(7, 0);
						placar = 0;
					}
					palDig[w] = ' ';

					if (placar == 5) {
						cout << "\nParabens! voce acertou";
						cout << "\nDenovo? [s] ou [S] para sim";
						cin >> rep;
						return 0;
					}
				}

			}
			cout << "- Digite: ";
		}
		cout << "\nA palavra era: " << palDia;
		cout << "\nDenovo? [s] ou [S] para sim: ";
		cin >> rep;
		if (rep != 's' || rep != 'S')
			repetir++;
	} while (repetir == 0);
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
