// npc: /d/xingxiu/npc/afanti.c
// Jay 3/26/96
inherit NPC;
//string ask_me();
void create()
{
        set_name("������", ({ "afanti" }) );
        set("gender", "����" );
        set("age", 48);
        set("long", 
            "��ͷ�ϰ���ͷ�����������̵İ��ֺ�����ϲ��׽Ū�������������ˡ�����"
            "�����˳����\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);
        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "�Ҿ������ն��İ����ᡣ",
            "here" : "��������Ǹ��õط���",
            "���ն�" : "���ҳ����ĵط���",
            "����" : "������ҵ�Сë¿���Ҿ͸�������",
            "����" : "�����ҹ�������г��кȣ��ҾͲ����ˡ������Ǹ�������Ը����ͷ�����",
            "ë¿" : "�ҵ�Сë¿���ҵ�ɳĮ��ƭ�����ֽ���ʱ�߶��ˡ�",
            "¿" : "�ҵ�Сë¿���ҵ�ɳĮ��ƭ�����ֽ���ʱ�߶��ˡ�",
            "Сë¿" : "�ҵ�Сë¿���ҵ�ɳĮ��ƭ�����ֽ���ʱ�߶��ˡ�",
            "������" : "������ָ�յ׸���˳��ߵ�������������ۡ�",
            "����" : "������������������������",
            "����" : "�����������������Ψ���������º�Ĭ����������ʹ�ߡ�",
       ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
             "������̾�˿������ˣ���ϧ�ҵ�¿��\n",
        }) );
       setup();
        carry_object("d/xingxiu/obj/wcloth")->wear();
        carry_object("d/xingxiu/obj/dongbula");
}
void init()
{
        ::init();
        add_action("do_answer","answer");
}
int accept_object(object who, object ob)
{
     if((string)ob->short()=="Сë¿(Donkey)") {
           if( who->query_temp("marks/��") ) {
                 write("������Ц��Ц��˵�����Ȱ��ϸ��ղ³�����˵��\n");
                 return 1;
           }
           else {
                 write("������Ц���춼�ϲ����ˣ�˵����л��λ" + 
                       RANK_D->query_respect(who) +
                       "�İ��������ǲ¸�����ɣ�\n");
                 switch(random(9)) {
                   case 0:
               write("����ϰ�(��һ����̶��������������)\n");
                       who->set_temp("marks/��", 6);
                       break;
                   case 1:
                       write("�����Ŷɶ���ȥ��(��һ����̶��ʦ)\n");
                       who->set_temp("marks/��", 9);
                       break;
                   case 2:
                       write("������ս�ܡ�(��һ����̶NPC��)\n");
                    // this riddle modified from one made by ţ����������
                       who->set_temp("marks/��", 10);
                       break;
                   case 3:
                       write("���굱����(��һ����̶NPC��)\n");
                    // this riddle made by ���¡���������
                       who->set_temp("marks/��", 11);
                       break;
                   case 4:
                       write("ŷ����������(��һ����)\n");
                    // this riddle made by ħ����������
                       who->set_temp("marks/��", 12);
                       break;
                   case 5:
                       write("�������ߡ�(��һ����̶NPC��)\n");
                    // this riddle made by ��ʿ����������
                       who->set_temp("marks/��", 13);
                       break;
                   case 6:
                       write("��˽ܿ�ѷ��(�������̶NPC��)----�ش�ʱ����һ��ش��м䲻���κα�㡣\n");
                       who->set_temp("marks/��", 14);
                       break;
                   case 7:
                       write("Ե��һϦ��δ�ɡ�(��һ����̶������)\n");
                    // this riddle made by �Ϲ����������� hanxx002@maroon.tc.umn.edu
                       who->set_temp("marks/��", 17);
                       break;
                   case 8:
                       write("�ؿۡ�(��һ����̶NPC��)\n");
                       who->set_temp("marks/��", 20);
                       break;
                  }
                  write("����˻ش� (answer) �ҡ���ס������й¶������յס�\n");
                  message("vision", "���������"+who->name()+"�ֹ��˼��仰��\n",
                          environment(who), ({who}) );
                  return 1;
            }
      }
}
int do_answer(string arg)
{
        object me,gold;
        int soln,riddle;
        me = this_player();
        riddle = this_player()->query_temp("marks/��");
        if (!riddle) {
           write("���ֲ�����ʦ�������ò��Żش��ҡ�\n");
           return 1;
        }
        if( !arg || arg=="" ) {
           write("����յ��ٻش�\n");
           return 1;
        }
        message("vision", me->name() + "����յ�������Ķ������ֹ�����\n",
                 environment(me), ({me}) );
        switch (arg) {
          case "��ѧ�ķ�" : soln=6; break;
          case "������" : soln=9; break;
          case "ŷ����" : soln=10; break;
          case "������" : soln=11; break;
          case "������ʩ" : soln=12; break;
          case "³�н�" : soln=13; break;
          case "���޳����޳�":
          case "���޳����޳�": soln=14; break;
          case "ŷ����ŷ����": soln=15; break;
      case "����": soln=17; break;
          case "������" : soln=20; break;
          default :
              say("�������Ц������˵������˵ʲôѽ��ţͷ�������졣\n"
                  + me->name() + "����������ͨ�졣\n");
              return 1;
        }
        if (riddle==soln) {
          gold = new("clone/money/gold");
          gold->move(this_player());
          say("���������" + me->name() + "һ���ƽ�\n");
          this_player()->set_temp("marks/��", 0);
          say ("�������" + me->name() + "�����ķָ����Ȼ��������ˡ��ƽ��ǰ����Ĳ���֮�ƣ�����ȥ�ָ����˰ɡ�\n");
          this_player()->add("combat_exp",80);
          write ("��ľ��������ˣ�\n");
        }
        else
          write ("˭���յ׸������? ����!!\n");
        return 1;
} 
 
   
