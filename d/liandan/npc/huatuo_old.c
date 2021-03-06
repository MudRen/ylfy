// By zjb@ty 2002-5-16

#include <ansi.h>;
inherit NPC;
int ask_me();
int ask_peifang();
void create()
{
    set_name("华佗", ({ "hua tuo", "hua", "tuo" }));
    set("title", "药铺老板");
    set("gender", "男性");
    set("long", "他就是医术高超的「妙手仁心」华佗。\n");
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
    "看病":(:ask_me:),     
    "配方":(:ask_peifang:),
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
    write(HIR"您的手臂受伤严重,已经造成了残废,让我来给你开张方子,去练个丹治疗一下吧!\n"NOR);
    me->set_temp("peifang","str");
    }
    
    if ( me->query("daoxin/dex")) {
    write(HIR"您的腿部受伤严重,已经造成了残废,让我来给你开张方子,去练个丹治疗一下吧!\n"NOR);
    me->set_temp("peifang","dex");
    }

    if ( me->query("daoxin/con")) {
    write(HIR"您的内伤十分严重,已经造成了残废,让我来给你开张方子,去练个丹治疗一下吧!\n"NOR);
    me->set_temp("peifang","con");
    }

    if ( !me->query("daoxin/con")&&!me->query("daoxin/str")&&!me->query("daoxin/dex")) {
me->delete("daoxin");
write(HIR"恭喜你又重新变成一位健康人了!\n"NOR);
}

}
else {
write(HIR"您很健康呀!\n"NOR);
me->delete("daoxin");
}
return 1;
}

int ask_peifang()
{
    object me = this_player();

    if ( !me->query_temp("peifang"))
    return notify_fail("我还不知道你得什么病呢,先让我看看病吧!\n");

    if ( me->query_temp("peifang") == "str") {
    write(HIG"您的病是手臂部位残废,治疗该部位的丹药有--\n"NOR);
    write(HIB"(伤药丸):主药为:千年何首乌,\n 普通药物:丹参,三七,地鳖虫 ,自然铜,骨碎补,冰片,血竭!\n\n"NOR);

     write(HIC"(补伤丸):主药为:千年人参,\n 普通药物:丹参,骨碎补,三七,龙骨,自然铜!\n\n"NOR);

     write(HIM"(先复汤):主药为:茯苓,\n 普通药物:没药,红花,没药,白芷!水煎喝!\n\n"NOR);

     write(HIR"(复方血竭酊):主药为:鹿茸,\n 普通药物:红花,白芷,没药,血竭 !\n\n"NOR);
     
     me->delete_temp("peifang");
return 1;
}

    if ( me->query_temp("peifang") == "dex") {
    write(HIG"您的病是腿部残废,治疗该部位的丹药有--\n"NOR);
    write(HIB"(活血止痛汤):主药为:熊掌,\n 普通药物:红花,丹参,没药!水煎喝!\n\n"NOR);

    write(HIR"(宋氏接骨散):主药为:万年人参,\n 普通药物:骨碎补,红花,地鳖虫,自然铜,血竭,没药!\n\n"NOR);

     me->delete_temp("peifang");
return 1;
}
    if ( me->query_temp("peifang") == "con") {
    write(HIG"您的病是内伤,治疗该伤的丹药有--\n"NOR);
    write(HIR"(祛腐生肌散):主药为:万年何首乌,\n 普通药物:没药,血竭,三七!\n\n"NOR);

    write(HIR"(七厘丹):主药为:万年茯苓,\n 普通药物:血竭,冰片,没药,红花!\n\n"NOR);

    write(HIR"(壮筋续骨丹):主药为:千年雪莲,\n 普通药物:骨碎补,地鳖虫,龙骨!\n\n"NOR);

    write(HIR"(朱砂没药散):主药为:万年雪莲,\n 普通药物:血竭,没药,地鳖虫,自然铜!\n\n"NOR);

     me->delete_temp("peifang");
return 1;
}

}
