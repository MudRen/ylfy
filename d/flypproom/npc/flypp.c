// flypp.c ����
// FLYPP 2003/10/17
inherit NPC;
void create()
{
set_name("����", ({ "flypp" }));
set("title",HIM"�ϵ����"NOR);
 set("nickname",HIC"�������"NOR);
set("long", "���Ƿ���¥��¥������˵����¥��һ�����ص���֯����ʼ�˷�����书�����ܵУ�����ȴ����û��˵������¥���˳��������߶�����֣���֡�����\n");	
set("gender", "����");
set("age", 22);
set("attitude", "friendly");
set("shen_type", 0);
set("str", 35);
set("int", 35);
set("con", 35);
set("dex", 85);	
set("max_qi", 3500000);	
set("max_jing", 2000000);
set("max_jingli", 100000);	
set("max_neili", 500000);
set("neili", 15000000);  	
set("shen", -150000000);	
set("breakup", 1);	
set("jiali", 50000);	
set("is_boss", 1);
set("combat_exp", 1000000000);
set("score", 35000);                                 
set_skill("literate", 35000);
set_skill("unarmed", 3500);
set_skill("dodge", 3500);
set_skill("sword", 3500);
set_skill("parry", 3500);
set_skill("force", 3500);
set_skill("adai-quanfa", 3500);
set_skill("yan-shuangfei", 3500);
set_skill("jiuyang-shengong", 3500);
set_skill("douzhuan-xingyi", 3500);
set_skill("mantianhuayu", 3500);
set_skill("riyue-bian", 3500);
set_skill("taiji-jian", 3500);
set_skill("qufeng", 3500);
set_skill("taoism", 3500);
set_skill("pixie-jian", 1000);
set_skill("qimen-wuxing", 3500);
set_skill("wuming-jianfa", 2000);
map_skill("throwing", "mantianhuayu");
map_skill("sword", "taiji-jian");       
map_skill("parry", "douzhuan-xingyi");       
map_skill("force", "jiuyang-shengong");       
map_skill("unarmed", "adai-quanfa");      
map_skill("dodge", "yan-shuangfei");
prepare_skill("unarmed", "adai-quanfa");	
set("chat_chance_combat", 350);          	
set("chat_msg_combat", ({
(: perform_action, "sword.chanup" :),	
(: perform_action, "sword.lianup" :),	
(: perform_action, "unarmed.aiai" :),
(: exert_function, "recover" :),
}));
set("inquiry", ([	
"name" : CYN "�Ҿ��Ƿ���¥¥�� "HIG" ���졣" NOR,	
"����¥" : BLU "�ٺ�,�����ҷ���¥�ɲ�����ô���׵���!" NOR, 
"������" : HIC "�����,һ���׳�Ҳֵ������???,�Ǻǣ�Ҳ����������׳�:) \n $N������������Ц������" NOR, 
"����" : HIM "����,һ��ɵɵ��СŮ��,����ͦ�ɰ���:)" NOR,
"��ս" : HIR "û�㱾�¿ɱ����������۰�...�����������Σ�յ�,���˿ɱ��!" NOR,
"��Ʒ" : HIW "Ϧ���ľ������������ϣ����б��´����ҾͿ��Եõ�:)" NOR,	
"ר����̨" : HIR "����Ƿ���¥ר����̨�����Դ����˵ģ���̨������Լ�ʬ�壬�ǵô�����֮��Ҫ��ȥ�����ս��ƷŶ~" NOR,
]) );
setup();
carry_object("/d/flypproom/wuping/fei tian")->wield();	
carry_object("/clone/cloth/zixuan")->wear();	
carry_object("/clone/cloth/lingyun")->wear();	
carry_object("/clone/cloth/fengting")->wear();
carry_object("/clone/cloth/qiankun")->wear();
carry_object("/clone/weapon/huolin")->wear();
carry_object("/d/flypproom/wuping/tianmojie")->wear();
carry_object("/d/flypproom/wuping/baiyushouzhuo")->wear();
carry_object("/d/taishan/obj/pie");
carry_object("/clone/weapon/longyin");
add_money("thousand-gold",3);  	
//   add_money("coin",20);	
}
void init()
{
object ob;
::init();
if (interactive(ob = this_player()) && !is_fighting()) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
add_action("do_sell", "sell");
}
}
void greeting(object me)
{
if (!me || environment(me) != environment() ) return;
command("look " + me->query("id"));

if (me->query("id")=="suimeng") {
command("say ��Ҳ��һ�������,��ϧ��Ȼ��������һ��"); 
command("sigh");                                   	
}
return ;
}
