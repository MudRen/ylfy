// bai.������
inherit NPC;
inherit F_MASTER;
int ask_lunjian(string str);		
int ask_kaiqi(string str);            	
void create()
{
set_name("������", ({"bai xiaosheng", "bai", "xiaosheng"}));
set("nickname", "������");
set("gender", "����");
set("age", 35);
set("long", 
"һ�����,�����еĲ�����.������֪,��������.��������.����Ϊ��ɽ�۽�Ȩ��������.\n");
set("attitude", "peaceful");
set("str", 100);
set("int", 100);
set("con", 100);
set("dex", 100);
set("breakup", 1);	
set("neili", 15000000);	
set("max_neili", 5000);
set("jiali", 50000);
set("max_jingli", 50000);	
set("jingli", 100000);	
set("max_qi", 3500000);	
set("max_jing", 3500000);	
set("combat_exp", 1500000000);
set_skill("sword", 3500);	
set_skill("dodge", 3500);	
set_skill("parry", 3500);	
set_skill("unarmed", 3500);	
set_skill("force", 3500);	
set_skill("jiuyang-shengong", 3500);	
set_skill("anranxiaohun-zhang", 3500);	
set_skill("douzhuan-xingyi", 3500);	
set_skill("qufeng", 3500);     	
set_skill("qimen-wuxing", 3500);     	
set_skill("yan-shuangfei", 3500);	
set_skill("taiji-jian", 3500);	
map_skill("dodge", "yan-shuangfei");	
map_skill("force", "jiuyang-shengong");	
map_skill("unarmed", "anranxiaohun-zhang");	
map_skill("parry", "douzhuan-xingyi");	
map_skill("sword", "taiji-jian");	
set("inquiry", ([
"��ɽ�۽�" : (: ask_lunjian :),	
"�ٿ��۽�" : (: ask_kaiqi :), 	
]));
create_family("��ħ��", 1, "����");
set("chat_chance_combat", 300);	
set("chat_msg_combat", ({	
(: perform_action, "sword.chanup" :),	
(: perform_action, "sword.lianup" :),	
(: exert_function, "recover" :),	
}) );	
setup();
carry_object("/d/lingxiao/obj/ganjiang")->wield();	
carry_object("/d/flypproom/wuping/tianmojie")->wear(); 	
carry_object("/d/city/npc/cloth/feature")->wear();  	
carry_object("/clone/npc/obj/battle_armor")->wear();   	
}
int ask_lunjian(string arg)		
{
object me;	
object bai;		
me = this_player();	
bai=this_object(); 		
if ( !bai->query("kaishi"))
{
command("say ����û�о��л�ɽ�۽�!");         	
return 1;		
}
if (me->query("age",1) < 15 )
{
command("say ��Ľ�����������������ĥ������������!");	
return 1;	
}
message_vision(CYN "һ���������,$N����Ӱ��Ȼ������\n" NOR,me); 	
me->move("/d/huashan/huashanjueding");
message_vision(CYN "$N����ӰͻȻ�����������С�\n" NOR,me);   
return 1;	
}
int ask_kaiqi(string arg)             	
{
object me;      	
object bai;              	
bai=this_object();              	
me = this_player();     	
if ( !wizardp(me) ) 
{
command("say ֻ����ʦ���ܿ�����ɽ�۽���");	
return 1;	
}
if (bai->query("kaishi"))
{
command("say ��ɽ�۽����ھ��С�");      	
return 1;       	
}
message("chat", HIY"����ɽ�۽���"+HIM"��ɽ���������۽����,����Ӻ���ʽ��ʼ,��λ�����������������μӣ�\n"NOR,users() );                     	
call_out("kaishi", 120, this_object());  	
bai->set("kaishi",1);
return 1;	
}
void kaishi(object bai)   	
{
message("chat", HIY"����ɽ�۽���"+HIM"���뿪ʼʱ�仹��������,�μӻ�ɽ�۽������ѸϿ�ǰ��������\n"NOR,users() );                  	
call_out("yubei", 120, this_object());           	
}
void yubei(object bai)       	
{
message("chat", HIY"����ɽ�۽���"+HIM"��ʣ���һ����,�μӻ�ɽ�۽��������ٲ�������û�����ˣ�\n"NOR,users() );             
call_out("zhuyi", 60, this_object());           	
}
void zhuyi(object bai)       	
{
message("chat", HIY"����ɽ�۽���"+HIM"��ɽ�۽�ֹͣ����,��ʽ��ʼ��\n"NOR,users() );        		
bai->delete("kaishi");
}
