// bojuan-xia.c
inherit ITEM;
void create()
{
    set_name("����", ({ "bo juan", "bo", "juan" }));
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
            "����һ��������д�� ��\n"
            "ׯ�ӡ���ң�Ρ����ƣ��֮����ڤ���ߣ����Ҳ�������ɣ������ǧ�������\n");
        set("value", 500);
        set("material", "silk");
        }
}
void init()
{
    if( this_player() == environment() )
    {
    add_action("do_study", "study");
    add_action("do_study", "du");
    }
}
int do_study(string arg)
{
    mapping skl;
    string *sname;

    int i, t, nf, j, nh;
    object me = this_player();

    i = (int)me->query_skill("xiaowuxiang", 1);
    t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;

    if (!arg || !id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_busy()) return notify_fail("��������æ���ء�\n");

    if (!me->query_temp("duxiaowu") ) { 
        set("skill", ([
            "name": "beiming-shengong", // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    19  // the maximum level you can learn
        ]) );
    if (me->query("family/family_name")!="��ң��") { 
        tell_object(me,"��ѧ������ı�ڤ�񹦣������������ң�ɡ�\n"); 
        return 1;
        }
    if ( me->is_fighter()) return notify_fail("ս�����޷��Ķ���֪��\n");
    if ( (int)me->query_skill("beiming-shengong",1) >= 20 
    && (int)me->query_skill("beiming-shengong",1) <= 100 )
    {
        me->receive_damage("jing", 20);
        me->improve_skill("beiming-shengong", (me->query_skill("beiming-shengong")
    +me->query_int()));
        message_vision("$N����ר���ж���ڤ���ķ���\n", me);
        return 1;
        }
    } else {
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ�����㣬����ѧС���๦��\n");
    if ( me->query("gender") == "����" && i > 49)
        return notify_fail("���޸����ԣ����������������������С���๦��\n");
    if (me->query_skill("force",1)<=i)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    if (i<= 404)
        return notify_fail("���С���๦������������ѧ��ȥ���߻���ħ�ġ�\n");
    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("xiaowuxiang", 1);
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧС���๦��\n");
    }
    if ( me->is_fighter()){
        tell_object(me,"ս�����޷��Ķ���֪��\n");
        return 1;
    }
    if (me->query("jing")>20){
            me->receive_damage("jing", 20);
            if(nh/3 <nf )
               me->improve_skill("xiaowuxiang", (me->query_skill("xiaowuxiang")+me->query_int()));
     }
    message_vision("$N����ר���ж���ң���ķ���\n", me);
    return 1;
    }
    return 0;
}

int query_autoload() { return 1; }