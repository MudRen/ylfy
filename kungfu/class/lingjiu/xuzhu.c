// /NPC xuzhu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("����", ({ "xu zhu", "xu", "zhu" }));
    set("long",
        "����һ����ʮ�������������, Ũü����,\n"+
        "���ı��ӱ�ƽ����, ��ò��Ϊ��ª. \n"+
        "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
        "��������ɽͯ�ѵľ�������.\n");
    set("title", "���չ�������");
    set("gender", "����");
    set("age", 26);
    set("nickname", HIR "����" NOR);
    set("attitude", "peaceful");
    set("str", 100);
    set("int", 65);
    set("con", 40);
    set("dex", 130);
    set("qi", 2500000);
    set("max_qi", 2500000);
    set("jing", 1205000);
    set("max_jing", 1200000);
    set("neili", 4000000);
    set("max_neili", 500000);
    set("jiali", 12000);
    set("max_jingli", 200000);
    set("jingli", 400000);
	set("xyzx_sys/level", 1000);
       set("combat_exp",5500000+random(10000000));
    set("score", 20000);
    set_skill("force", 2800);
    set_skill("unarmed", 2800);
      set_skill("literate", 2800);
    set_skill("dodge", 2100);
     set_skill("parry", 2750);
     set_skill("sword", 2750);
     set_skill("tianyu-qijian", 1550);
    set_skill("zhemei-shou",1000);
    set_skill("liuyang-zhang",1900);
     set_skill("yueying-wubu",1800);
      set_skill("bahuang-gong", 1850);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    create_family("���չ�",2, "����");
    setup();
    carry_object("/clone/cloth/changpao")->wear();
    add_money("silver",50);
}
void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
           {
        command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
        return;
       }  
   if ((string)ob->query("gender")=="Ů��")
   {
        message_vision("����Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "dancer")
            ob->set("class", "dancer");
       return;}
   else
      {
        message_vision("��������㿴�˰���,˵���������²������������ҵ������?��\n",ob);
       return;}
}
