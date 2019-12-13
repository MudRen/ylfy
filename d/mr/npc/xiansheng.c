// teacher.c ˽������
// CLEANSWORD 1999/9/7
inherit NPC;
#include <ansi.h>
string * degree_desc = ({
       BLU "��ä" NOR,
       BLU "ͯ��" NOR,
       BLU "���" NOR,
       CYN "����" NOR,
       CYN "��Ԫ" NOR,
       CYN "��ʿ" NOR,
       CYN "��Ԫ" NOR,
       GRN "��ʿ" NOR,
       GRN "̽��" NOR,
       GRN "����" NOR,
       GRN "״Ԫ" NOR,
       HIY "����Ժʿ" NOR,
       HIY "����˶ʿ" NOR,
       HIY "���ֲ�ʿ" NOR,
       HIY "����Ժ����" NOR,
       HIR "����ʿ" NOR,
       HIR "ѧʿ" NOR,
       HIR "�ڸ��ѧʿ" NOR,
       HIR "�ڸ��׸�" NOR,
       MAG "��ѧ����ʦ" NOR,
       HIW "ʥ��" NOR,
});
int ask_degree();
void create()
{
        set_name("˽������", ({ "xiansheng", "teacher" }));
        set("long", "�����Ľ�ݼ��ؽ���Ƹ����˽�����������ǵ������������ѧ����?��������������ʦ�������ɣ�����Ϊ����������ī������ѧλ\n");
        set("gender", "����");
        set("age", 65); 
        set_weight(30000000);
        set_skill("literate", 300);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "ѧλ" : (:ask_degree:),
            "��"   : "��!�鵽��ʱ�����١�",
            "����" : "�裿�㲻���ҵ��������㣿��!",
        ]));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "˽������˵��������֮�£�Ī������������֮����Ī��������\n",
                "˽������˵���������ˣ�С�������ɣ����������δ������֮��\n",
                "˽������˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
                "˽������˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
        }) );
     carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0; 
        ob->add_temp("mark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 5000) {
                message_vision("˽������ͬ��ָ��$NһЩ���⡣\n", who);
                who->add_temp("mark/��", ob->value() / 250);
                return 1;
        }
        return 0;
}
int ask_degree()
{
        int lv;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 5);
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 3) 
        {
               command("say "+ob->query("name")+"�����ǵ�īˮҲ����˼��? �������ѧλ������! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        if (lv < 10) 
        {
               command("say "+ob->query("name")+"������������ǰ;���ܸ�������ѧλ���㣬�����ú�Ŭ��! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        else
        {
               command("say ��Ȼ�ǳ���������ǰ�˰���"+ob->query("name")+"���ҷǳ��������л���Ϊ����ѧλ! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
}

