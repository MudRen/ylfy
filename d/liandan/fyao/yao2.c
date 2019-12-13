// By zjb@ty
// update by Wenwu

inherit ITEM; 

mapping *ansi = ({
	([ "yanse" : HIC ]),
	([ "yanse" : HIG ]),
	([ "yanse" : HIR ]),
	([ "yanse" : HIB ]),
	([ "yanse" : HIM,]),
	([ "yanse" : HIY,]),
	([ "yanse" : RED,]),
	([ "yanse" : YEL,]), 
	([ "yanse" : MAG,]),
	([ "yanse" : CYN,]),
	});

mapping *yao = ({
	([  "name"   : "����",
		"id"     : "dang gui",
		"shoubi" : random(3),   
		"random" : random(5),
		"tui"    : random(3),
	]),
	([  "name"   : "����",
		"id"     : "chuan jiao",
		"shoubi" : random(3),   
		"random" : random(3),
		"tui"    : random(3), 
	]),
	([  "name"   : "����",
		"id"     : "chi shao",
		"shoubi" : random(3),   
		"random" : random(4),
		"all"    : random(3),
		"tui"    : random(3), 
	]),
	([  "name"   : "����",
		"id"     : "ze lan",
		"shoubi" : random(3),   
		"random" : 2,
		"all"    : random(3),
		"tui"    : random(3),
	]),
	([  "name"   : "����",
		"id"     : "yu zhu",
		"shoubi" : random(3),   
		"random" : 3,
		"all"    : random(3),
		"tui"    : random(3),
	]),
	([	"name"   : "������",
		"id"     : "wuming yi",
		"shoubi" : random(3),   
		"random" : 6,
		"all"    : random(3),
		"tui"    : random(3),
	]),
	([  "name"   : "�ư�",
		"id"     : "huang bo",
		"shoubi" : random(3),   
		"random" : 4,
		"all"    : random(3),
		"tui"    : random(3),
	]),

	([  "name"   : "��Ƥ",
		"id"     : "chen pi",
		"shoubi" : random(3),
		"random" : 5,
		"all"    : random(3),
		"tui"    : random(3),
	]),
	([  "name"   : "�ɽ�",
		"id"     : "song jie",
		"shoubi" : random(3),   
		"random" : 7,
		"all"    : random(3),
		"tui"    : random(3),
		]),
	([  "name"   : "�ʲ�",      
		"id"     : "gan cao", 
		"shoubi" : random(3),   
		"random" : 8,
		"all"    : random(3),
		"tui"    : random(3),
	]),
	([  "name"   : "��ĸ",
		"id"     : "bei mu",
		"shoubi" : random(3),   
		"random" : 9,
		"all"    : random(3),
		"tui"    : random(3),
	]),

});

void create()
{
	string name, id;
	int shoubi, tui, all, yaoo, yanse, all2;

    yanse = random(sizeof(ansi));
    yaoo = random(sizeof(yao));
    name = yao[yaoo]["name"];
    id = yao[yaoo]["id"]; 
    shoubi = yao[yaoo]["shoubi"]; 
    tui = yao[yaoo]["tui"];
    all = yao[yaoo]["all"];
    all2 = yao[yaoo]["random"];
    
	set_name(ansi[yanse]["yanse"]+name+NOR,({id}) );  
	set_weight(100);
	set("unit", "��");
	set("shoubi",shoubi);
	set("all",all);
	set("tui",tui);
	set("yao",1);
	set("random",all2);
	setup();
}