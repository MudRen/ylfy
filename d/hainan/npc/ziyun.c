// worker.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("����", ({"zi yun"}));
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "һ��Ư����С���");
	set("title", "�����ִ���");
	set("class", "taoist");
        set("combat_exp", 4500000);
        set("attitude", "peaceful");
        create_family("���ϰ�����", 4, "����");
        set_skill("unarmed", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("force", 330);   
set_skill("bitao-shengong",330);
        set_skill("baihua-zhang",360);
        set_skill("sword",350);
              set_skill("feixian-jian",360);
map_skill("force", "bitao-shengong");
        map_skill("sword","feixian-jian");

        set("per", 30);
        set("max_qi", 1500);
        set("max_jing", 3000);
        set("neili", 4500);
        set("max_neili", 3000);
        set("force_factor", 5);
        setup();
        carry_object("/d/hainan/obj/girlcloth")->wear();
        carry_object("/d/hainan/obj/roujing_sword")->wield();
              carry_object("/obj/money/gold");
}
void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
			call_out("greeting",1,ob);
}
}
void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
tell_object(ob,HIC"������һ����ˮ������,����������Ů�ӵ���Ц��!\n"+NOR);
  if (ob->query("gender")=="����")
   {
tell_object(ob,HIC+"���ż�������,����ǰһ��,�Ժ���һ��!\n
��ǰ��һ�б��ģģ����,Ȼ���ʲô����֪����!\n
..........    ..........\n"+NOR);
ob->unconcious();
message_vision(HIR"-------��------,���Ƽ��һ��,$N͵��Ů����ϴ��------ ------!\n
$N�Ժ��漴����һ����,�һ����г����������������Ů��,��$N��������������!\n"+NOR,ob);
tell_room("/d/hainan/dilao.c",RED"������ͻȻ��,"+ob->query("name")+"�����˽���!\n"+NOR);
ob->move("/d/hainan/dilao.c");
    }
else 
  message_vision(HIC"����Ц�����ض�$N˵��:��λ"+RANK_D->query_respect(ob)+"Ҳ����ϴ���ô?\n"+NOR,ob);
}


