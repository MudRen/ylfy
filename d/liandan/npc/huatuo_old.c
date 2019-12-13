// By zjb@ty 2002-5-16

#include <ansi.h>;
inherit NPC;
int ask_me();
int ask_peifang();
void create()
{
    set_name("��٢", ({ "hua tuo", "hua", "tuo" }));
    set("title", "ҩ���ϰ�");
    set("gender", "����");
    set("long", "������ҽ���߳��ġ��������ġ���٢��\n");
    set("age", 65);
    set("int", 30);
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("shen_type", 0);
    set("combat_exp", 500000);
    set("attitude", "heroism");
    set_skill("unarmed", 80);
    set_skill("dodge", 80);
    set_skill("parry", 60);
    set_temp("apply/attack", 70);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 50);
        set("inquiry", ([
    "����":(:ask_me:),     
    "�䷽":(:ask_peifang:),
        ]) );
    setup();
    add_money("gold", 1);
    carry_object("/clone/cloth/changpao")->wear();
} 

int ask_me()
{
    object me = this_player();

    if ( me->query("daoxin")) {
    if ( me->query("daoxin/str")) {
    write(HIR"�����ֱ���������,�Ѿ�����˲з�,���������㿪�ŷ���,ȥ����������һ�°�!\n"NOR);
    me->set_temp("peifang","str");
    }
    
    if ( me->query("daoxin/dex")) {
    write(HIR"�����Ȳ���������,�Ѿ�����˲з�,���������㿪�ŷ���,ȥ����������һ�°�!\n"NOR);
    me->set_temp("peifang","dex");
    }

    if ( me->query("daoxin/con")) {
    write(HIR"��������ʮ������,�Ѿ�����˲з�,���������㿪�ŷ���,ȥ����������һ�°�!\n"NOR);
    me->set_temp("peifang","con");
    }

    if ( !me->query("daoxin/con")&&!me->query("daoxin/str")&&!me->query("daoxin/dex")) {
me->delete("daoxin");
write(HIR"��ϲ�������±��һλ��������!\n"NOR);
}

}
else {
write(HIR"���ܽ���ѽ!\n"NOR);
me->delete("daoxin");
}
return 1;
}

int ask_peifang()
{
    object me = this_player();

    if ( !me->query_temp("peifang"))
    return notify_fail("�һ���֪�����ʲô����,�����ҿ�������!\n");

    if ( me->query_temp("peifang") == "str") {
    write(HIG"���Ĳ����ֱ۲�λ�з�,���Ƹò�λ�ĵ�ҩ��--\n"NOR);
    write(HIB"(��ҩ��):��ҩΪ:ǧ�������,\n ��ͨҩ��:����,����,�ر�� ,��Ȼͭ,���鲹,��Ƭ,Ѫ��!\n\n"NOR);

     write(HIC"(������):��ҩΪ:ǧ���˲�,\n ��ͨҩ��:����,���鲹,����,����,��Ȼͭ!\n\n"NOR);

     write(HIM"(�ȸ���):��ҩΪ:����,\n ��ͨҩ��:ûҩ,�컨,ûҩ,����!ˮ���!\n\n"NOR);

     write(HIR"(����Ѫ����):��ҩΪ:¹��,\n ��ͨҩ��:�컨,����,ûҩ,Ѫ�� !\n\n"NOR);
     
     me->delete_temp("peifang");
return 1;
}

    if ( me->query_temp("peifang") == "dex") {
    write(HIG"���Ĳ����Ȳ��з�,���Ƹò�λ�ĵ�ҩ��--\n"NOR);
    write(HIB"(��Ѫֹʹ��):��ҩΪ:����,\n ��ͨҩ��:�컨,����,ûҩ!ˮ���!\n\n"NOR);

    write(HIR"(���Ͻӹ�ɢ):��ҩΪ:�����˲�,\n ��ͨҩ��:���鲹,�컨,�ر��,��Ȼͭ,Ѫ��,ûҩ!\n\n"NOR);

     me->delete_temp("peifang");
return 1;
}
    if ( me->query_temp("peifang") == "con") {
    write(HIG"���Ĳ�������,���Ƹ��˵ĵ�ҩ��--\n"NOR);
    write(HIR"(�����ɢ):��ҩΪ:���������,\n ��ͨҩ��:ûҩ,Ѫ��,����!\n\n"NOR);

    write(HIR"(���嵤):��ҩΪ:��������,\n ��ͨҩ��:Ѫ��,��Ƭ,ûҩ,�컨!\n\n"NOR);

    write(HIR"(׳�����ǵ�):��ҩΪ:ǧ��ѩ��,\n ��ͨҩ��:���鲹,�ر��,����!\n\n"NOR);

    write(HIR"(��ɰûҩɢ):��ҩΪ:����ѩ��,\n ��ͨҩ��:Ѫ��,ûҩ,�ر��,��Ȼͭ!\n\n"NOR);

     me->delete_temp("peifang");
return 1;
}

}
