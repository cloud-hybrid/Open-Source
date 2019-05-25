#!/usr/bin/env python3.7.3
# ........................................................................... #
# (c) 2019, Jacob B. Sanders <development.cloudhybrid@gmail.com>
# GNU General Public License v3.0: https://opensource.org/licenses/GPL-3.0

METADATA = {
  "Module" : "TagListRemediation",
  "Package" : "IaaS",
  "Version" : "1.0",
  "Status" : "Completed[Closed]"
  }

DOCUMENTATION = """
Module: TagListRemediation
Author: Jacob B. Sanders (@cloud-hybrid)
Summary: Module used for correcting AWS key strings. 
Documentation: https://vaultcipher.com/

@Dependencies
  - Python 3.6+

@Development
  - Completed. No future plans for editions. 
"""

EXAMPLES = """
TAGLIST = [
    "AppIDTag",
    "CostCenterTag",
    "BillingTag",
    "AMITag"
]

REMEDIATIONS = {
    "AppIDTag" : "APP_ID",
    "CostCenterTag" : "COST_CENTER"
}
.
.
.
def main():
    dopplerTagRemediation()
"""

TAGLIST = [
    "AppIDTag",
    "CostCenterTag",
    "BillingTag",
    "AMITag"
]

REMEDIATIONS = {
    "AppIDTag" : "APP_ID",
    "CostCenterTag" : "COST_CENTER"
}

def printTagList():
    for index in TAGLIST:
        print(index)

def tagRemediation():
    for index in range(0, len(TAGLIST)):
        for tag, key in REMEDIATIONS.items():
            if TAGLIST[index] == tag:
                TAGLIST[index] = key
                print("Successful Change: " + f"{TAGLIST[index]}")

def main():
    print("\n" + "Non-Remediated Tag List: " + "\n")
    printTagList()
    print("\n")

    tagRemediation()
    print("\n")
    
    print("\n" + "Remediated Tag List: " + "\n")
    printTagList()
    print("\n")

if __name__ == "__main__":
    main()
