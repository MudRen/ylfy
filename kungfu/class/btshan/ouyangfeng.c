///ouyangfeng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
    set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
           +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
           +"����ң�������ͷɢ����\n");
    set("title", "�϶���");
    set("gender", "����");
    set("age", 53);
    set("nickname", HIR "����" NOR);
set("shen",-4000000);            	
           	
    set("attitude", "peaceful");
    set("str", 100);
    set("int", 70);
    set("con", 50);
    set("dex", 100);
    set("qi", 2000000);
    set("no_get",1);
    set("max_qi", 2000000);
    set("jing", 1000000);
    set("max_jing", 1000000);
    set("neili", 3000000);
    set("max_neili", 500000);
    set("jiali", 13000);
    set("combat_exp", 70000000);
	set("xyzx_sys/level", 1500);
//    set("score", 200000);
    set_skill("force", 2750);
    set_skill("unarmed", 2900);
     set_skill("dodge", 2800);
      set_skill("parry", 2940);
     set_skill("staff", 2000);
     set_skill("hamagong", 1280);
     set_skill("chanchu-bufa",1170);
     set_skill("training",1500);	
      set_skill("shexing-diaoshou",1300);
      set_skill("lingshe-zhangfa", 1000);
     map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "shexing-diaoshou");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
    create_family("����ɽ��",1, "��ɽ��ʦ");
        set("chat_chance",2);
        set("chat_msg",({
         "ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
         "ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
         "ŷ������������ն����������ģ�\n",
        }));
    setup();
    carry_object("/d/baituo/obj/shenshezhang")->wield();
    carry_object("/clone/cloth/cloth")->wear();
    add_money("silver",50);
}
void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<500000)
        {
          message_vision("ŷ�����$NЦ������ľ���̫����,�һ��������㣡\n",ob);
    return ;
         }
   message_vision("ŷ��������$N��ͷ��΢΢���˵�ͷ��\n",ob);
   command("recruit " + ob->query("id"));
   return;
}
