#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Base.h"
using namespace std;
// 存储课程信息
//自定义格式化函数，保证课程名长度一致
string formatCourseName(const string& name,int width) {
    string formatted = name;
    while (formatted.length() < width) {
        formatted += " ";
    }
    return formatted;
}
map<string, vector<Course>> softwareEngineering = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 95, 12, "张老师 ", "教室1"),
            Course(formatCourseName("计算机导论", 20), 95, 8, "李老师 ", "教室2"),
            Course(formatCourseName("计算机科学概论", 20), 90, 6, "王老师 ", "教室3"),
            Course(formatCourseName("计算机图形设计", 20), 95, 10, "赵老师", "教室4"),
            Course(formatCourseName("离散数学", 20), 90, 8, "刘老师 ", "教室5"),
            Course(formatCourseName("思想道德与法治修养", 20), 85, 6, "陈老师 ", "教室6")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("数据结构", 20), 95, 8, "赵老师", "教室7"),
            Course(formatCourseName("算法设计与分析", 20), 95, 8, "钱老师", "教室8"),
            Course(formatCourseName("计算机组成原理", 20), 90, 10, "孙老师", "教室9"),
            Course(formatCourseName("操作系统", 20), 95, 10, "周老师", "教室10"),
            Course(formatCourseName("数据库系统原理", 20), 90, 8, "吴老师", "教室11"),
            Course(formatCourseName("面向对象编程", 20), 95, 8, "郑老师", "教室12")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("软件工程管理", 20), 95, 8, "王老师", "教室13"),
            Course(formatCourseName("软件体系结构与设计模式", 20), 90, 8, "李老师", "教室14"),
            Course(formatCourseName("计算机网络体系结构", 20), 95, 8, "张老师", "教室15"),
            Course(formatCourseName("软件测试与质量保证", 20), 90, 8, "刘老师", "教室16"),
            Course(formatCourseName("软件工程实践", 20), 95, 10, "陈老师", "教室17"),
            Course(formatCourseName("软件项目管理", 20), 90, 8, "周老师", "教室18")
        }
    },
    {
        "大四",
        {
            Course(formatCourseName("软件安全与可靠性", 20), 95, 6, "赵老师", "教室19"),
            Course(formatCourseName("网络安全与攻防技术", 20), 90, 6, "钱老师", "教室20"),
            Course(formatCourseName("云计算与大数据分析", 20), 95, 6, "孙老师", "教室21"),
            Course(formatCourseName("人工智能算法基础", 20), 90, 6, "李老师", "教室22"),
            Course(formatCourseName("软件工程综合实践", 20), 95, 12, "王老师", "教室23")
        }
    }
};

map<string, vector<Course>> computerScience = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室24"),
            Course(formatCourseName("数学分析", 20), 90, 8, "李老师", "教室25"),
            Course(formatCourseName("专业英语", 20), 90, 6, "王老师", "教室26"),
            Course(formatCourseName("程序设计基础", 20), 100, 10, "赵老师", "教室27"),
            Course(formatCourseName("计算机图形设计", 20), 100, 8, "刘老师", "教   室28"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室29")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("离散数学", 20), 90, 8, "张老师", "教室30"),
            Course(formatCourseName("数据结构", 20), 100, 8, "李老师", "教室31"),
            Course(formatCourseName("计算机组成原理", 20), 100, 12, "王老师", "教室32"),
            Course(formatCourseName("操作系统", 20), 100, 12, "赵老师", "教室33"),
            Course(formatCourseName("编程语言", 20), 100, 8, "刘老师", "教室34"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室35")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("算法设计与分析", 20), 100, 6, "张老师", "教室36"),
            Course(formatCourseName("编译原理", 20), 100, 16, "李老师", "教室37"),
            Course(formatCourseName("数据库原理", 20), 100, 6, "王老师", "教室38"),
            Course(formatCourseName("计算机原理", 20), 100, 6, "赵老师", "教室39"),
            Course(formatCourseName("网络安全基础", 20), 100, 6, "刘老师", "教室40")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> electronicEngineering = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室41"),
            Course(formatCourseName("数学分析", 20), 90, 8, "李老师", "教室42"),
            Course(formatCourseName("专业英语", 20), 90, 6, "王老师", "教室43"),
            Course(formatCourseName("电路原理", 20), 100, 10, "赵老师", "教室44"),
            Course(formatCourseName("工程制图", 20), 90, 8, "刘老师", "教室45"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室46")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("模拟电子技术", 20), 100, 8, "张老师", "教室47"),
            Course(formatCourseName("数字电子技术", 20), 100, 8, "李老师", "教室48"),
            Course(formatCourseName("信号系统", 20), 100, 12, "王老师", "教室49"),
            Course(formatCourseName("自动控制原理", 20), 100, 12, "赵老师", "教室50"),
            Course(formatCourseName("通信原理", 20), 100, 8, "刘老师", "教室51"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室52")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("单片机原理及应用", 20), 100, 6, "张老师", "教室53"),
            Course(formatCourseName("传感器原理及应用", 20), 100, 6, "李老师", "教室54"),
            Course(formatCourseName("嵌入式系统设计", 20), 100, 16, "王老师", "教室55"),
            Course(formatCourseName("电力电子技术", 20), 100, 6, "赵老师", "教室56"),
            Course(formatCourseName("电子电路设计", 20), 100, 6, "刘老师", "教室57")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> mechanicalEngineering = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室58"),
            Course(formatCourseName("数学分析", 20), 90, 8, "李老师", "教室59"),
            Course(formatCourseName("专业英语", 20), 90, 6, "王老师", "教室60"),
            Course(formatCourseName("工程制图", 20), 90, 8, "赵老师", "教室61"),
            Course(formatCourseName("机械设计基础", 20), 100, 10, "刘老师", "教室62"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室63")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("理论力学", 20), 100, 8, "张老师", "教室64"),
            Course(formatCourseName("材料力学", 20), 100, 8, "李老师", "教室65"),
            Course(formatCourseName("机械制造技术基础", 20), 100, 12, "王老师", "教室66"),
            Course(formatCourseName("机电传动控制", 20), 100, 12, "赵老师", "教室67"),
            Course(formatCourseName("液压与气压传动", 20), 90, 6, "刘老师", "教室68"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室69")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("机械原理", 20), 100, 6, "张老师", "教室70"),
            Course(formatCourseName("机械设计", 20), 100, 16, "李老师", "教室71"),
            Course(formatCourseName("机械优化设计", 20), 100, 6, "王老师", "教室72"),
            Course(formatCourseName("机械制造装备设计", 20), 100, 6, "赵老师", "教室73"),
            Course(formatCourseName("机械系统动力学", 20), 100, 6, "刘老师", "教室74")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> civilEngineering = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室75"),
            Course(formatCourseName("数学分析", 20), 90, 8, "李老师", "教室76"),
            Course(formatCourseName("专业英语", 20), 90, 6, "王老师", "教室77"),
            Course(formatCourseName("工程制图", 20), 90, 8, "赵老师", "教室78"),
            Course(formatCourseName("工程测量学", 20), 100, 10, "刘老师", "教室79"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室80")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("理论力学", 20), 100, 8, "张老师", "教室81"),
            Course(formatCourseName("材料力学", 20), 100, 8, "李老师", "教室82"),
            Course(formatCourseName("结构力学", 20), 100, 12, "王老师", "教室83"),
            Course(formatCourseName("工程地质学", 20), 90, 6, "赵老师", "教室84"),
            Course(formatCourseName("土力学", 20), 100, 8, "刘老师", "教室85"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室86")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("混凝土结构设计原理", 20), 100, 6, "张老师", "教室87"),
            Course(formatCourseName("钢结构设计原理", 20), 100, 6, "李老师", "教室88"),
            Course(formatCourseName("土木工程施工技术", 20), 100, 12, "王老师", "教室89"),
            Course(formatCourseName("工程结构抗震", 20), 100, 8, "赵老师", "教室90"),
            Course(formatCourseName("建筑施工组织", 20), 100, 6, "刘老师", "教室91")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> chemistry = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室92"),
            Course(formatCourseName("数学分析", 20), 90, 8, "李老师", "教室93"),
            Course(formatCourseName("专业英语", 20), 90, 6, "王老师", "教室94"),
            Course(formatCourseName("无机化学", 20), 100, 10, "赵老师", "教室95"),
            Course(formatCourseName("分析化学", 20), 90, 8, "刘老师", "教室96"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室97")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("有机化学", 20), 100, 8, "张老师", "教室98"),
            Course(formatCourseName("物理化学", 20), 100, 12, "李老师", "教室99"),
            Course(formatCourseName("仪器分析", 20), 100, 6, "王老师", "教室100"),
            Course(formatCourseName("结构化学", 20), 100, 6, "赵老师", "教室101"),
            Course(formatCourseName("化学实验基础", 20), 100, 8, "刘老师", "教室102"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室103")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("高分子化学", 20), 100, 6, "张老师", "教室104"),
            Course(formatCourseName("催化原理", 20), 100, 16, "李老师", "教室105"),
            Course(formatCourseName("高等有机化学", 20), 100, 6, "王老师", "教室106"),
            Course(formatCourseName("波谱分析", 20), 100, 6, "赵老师", "教室107"),
            Course(formatCourseName("有机合成化学", 20), 100, 6, "刘老师", "教室108")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> biology = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室109"),
            Course(formatCourseName("数学分析", 20), 90, 8, "李老师", "教室110"),
            Course(formatCourseName("专业英语", 20), 90, 6, "王老师", "教室111"),
            Course(formatCourseName("植物学", 20), 100, 10, "赵老师", "教室112"),
            Course(formatCourseName("动物学", 20), 90, 8, "刘老师", "教室113"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室114")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("生物化学", 20), 100, 12, "张老师", "教室115"),
            Course(formatCourseName("细胞生物学", 20), 100, 8, "李老师", "教室116"),
            Course(formatCourseName("遗传学", 20), 100, 8, "王老师", "教室117"),
            Course(formatCourseName("微生物学", 20), 100, 8, "赵老师", "教室118"),
            Course(formatCourseName("生态学", 20), 90, 6, "刘老师", "教室119"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室120")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("分子生物学", 20), 100, 6, "张老师", "教室121"),
            Course(formatCourseName("基因工程", 20), 100, 6, "李老师", "教室122"),
            Course(formatCourseName("生物制药", 20), 100, 16, "王老师", "教室123"),
            Course(formatCourseName("生物统计学", 20), 100, 6, "赵老师", "教室124"),
            Course(formatCourseName("发育生物学", 20), 100, 6, "刘老师", "教室125")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> economics = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室126"),
            Course(formatCourseName("专业英语", 20), 90, 6, "李老师", "教室127"),
            Course(formatCourseName("经济学原理", 20), 100, 10, "王老师", "教室128"),
            Course(formatCourseName("管理学原理", 20), 90, 8, "赵老师", "教室129"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室130")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("微观经济学", 20), 100, 8, "张老师", "教室131"),
            Course(formatCourseName("宏观经济学", 20), 100, 8, "李老师", "教室132"),
            Course(formatCourseName("统计学", 20), 100, 8, "王老师", "教室133"),
            Course(formatCourseName("会计学", 20), 100, 8, "赵老师", "教室134"),
            Course(formatCourseName("财政学", 20), 90, 6, "刘老师", "教室135"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室136")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("计量经济学", 20), 100, 6, "张老师", "教室137"),
            Course(formatCourseName("金融经济学", 20), 100, 6, "李老师", "教室138"),
            Course(formatCourseName("企业经济学", 20), 100, 16, "王老师", "教室139"),
            Course(formatCourseName("投资学", 20), 100, 6, "赵老师", "教室140"),
            Course(formatCourseName("发展经济学", 20), 100, 6, "刘老师", "教室141")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> management = {
    {
        "大一",
        {
            Course(formatCourseName("高等数学", 20), 100, 12, "张老师", "教室142"),
            Course(formatCourseName("专业英语", 20), 90, 6, "李老师", "教室143"),
            Course(formatCourseName("管理学原理", 20), 100, 10, "王老师", "教室144"),
            Course(formatCourseName("公关礼仪学", 20), 90, 8, "赵老师", "教室145"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室146")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("组织行为学", 20), 100, 8, "张老师", "教室147"),
            Course(formatCourseName("人力资源管理", 20), 100, 8, "李老师", "教室148"),
            Course(formatCourseName("市场营销学", 20), 100, 8, "王老师", "教室149"),
            Course(formatCourseName("财务管理", 20), 100, 8, "赵老师", "教室150"),
            Course(formatCourseName("统计学", 20), 90, 6, "刘老师", "教室151"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室152")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("战略管理", 20), 100, 6, "张老师", "教室153"),
            Course(formatCourseName("管理信息系统", 20), 100, 6, "李老师", "教室154"),
            Course(formatCourseName("项目管理", 20), 100, 16, "王老师", "教室155"),
            Course(formatCourseName("公关策划", 20), 100, 6, "赵老师", "教室156"),
            Course(formatCourseName("运营管理", 20), 100, 6, "刘老师", "教室157")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> journalism = {
    {
        "大一",
        {
            Course(formatCourseName("专业英语", 20), 90, 6, "张老师", "教室158"),
            Course(formatCourseName("新闻学概论", 20), 100, 10, "李老师", "教室159"),
            Course(formatCourseName("传播学概论", 20), 90, 8, "王老师", "教室160"),
            Course(formatCourseName("中国新闻事业史", 20), 100, 8, "赵老师", "教室161"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室162")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("新闻采访与写作", 20), 100, 8, "张老师", "教室163"),
            Course(formatCourseName("新闻编辑与评论", 20), 100, 8, "李老师", "教室164"),
            Course(formatCourseName("新闻摄影", 20), 90, 6, "王老师", "教室165"),
            Course(formatCourseName("广播电视新闻学", 20), 100, 8, "赵老师", "教室166"),
            Course(formatCourseName("网络与新媒体概论", 20), 100, 8, "刘老师", "教室167"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室168")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("新闻伦理学", 20), 100, 6, "张老师", "教室169"),
            Course(formatCourseName("新闻职业精神与职业道德", 20), 100, 6, "李老师", "教室170"),
            Course(formatCourseName("媒介经营与管理", 20), 100, 16, "王老师", "教室171"),
            Course(formatCourseName("新闻摄影与摄像", 20), 100, 6, "赵老师", "教室172"),
            Course(formatCourseName("新闻传播前沿研究", 20), 100, 6, "刘老师", "教室173")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, vector<Course>> law = {
    {
        "大一",
        {
            Course(formatCourseName("专业英语", 20), 90, 6, "张老师", "教室174"),
            Course(formatCourseName("法学概论", 20), 100, 10, "李老师", "教室175"),
            Course(formatCourseName("中国法制史", 20), 90, 8, "王老师", "教室176"),
            Course(formatCourseName("法理学", 20), 100, 8, "赵老师", "教室177"),
            Course(formatCourseName("思想道德与法治修养", 20), 100, 8, "陈老师", "教室178")
        }
    },
    {
        "大二",
        {
            Course(formatCourseName("宪法学", 20), 100, 8, "张老师", "教室179"),
            Course(formatCourseName("民法学", 20), 100, 8, "李老师", "教室180"),
            Course(formatCourseName("刑法学总论", 20), 100, 8, "王老师", "教室181"),
            Course(formatCourseName("刑法学分论", 20), 100, 8, "赵老师", "教室182"),
            Course(formatCourseName("行政法与行政诉讼法", 20), 100, 8, "刘老师", "教室183"),
            Course(formatCourseName("概率论", 20), 90, 6, "陈老师", "教室184")
        }
    },
    {
        "大三",
        {
            Course(formatCourseName("刑事诉讼法学", 20), 100, 6, "张老师", "教室185"),
            Course(formatCourseName("知识产权法", 20), 100, 6, "李老师", "教室186"),
            Course(formatCourseName("商法学", 20), 100, 16, "王老师", "教室187"),
            Course(formatCourseName("经济法学", 20), 100, 6, "赵老师", "教室188"),
            Course(formatCourseName("国际经济法学", 20), 100, 6, "刘老师", "教室189")
        }
    },
    {
        "大四",
        {}
    }
};

map<string, map<string, vector<Course>>> course = {
    {"软件工程",softwareEngineering},
    {"计算机科学与技术",computerScience},
    {"电子工程",electronicEngineering},
    {"机械工程",mechanicalEngineering},
    {"土木工程",civilEngineering},
    {"化学",chemistry},
    {"生物学",biology},
    {"经济学",economics},
    {"管理学",management},
    {"新闻学",journalism},
    {"法学",law}
};
